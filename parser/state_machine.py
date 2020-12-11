#!/usr/bin/python3

class printing_format:
	def __init__(self):
		self.flag = ""
		self.width = -1
		self.mod = ""
		self.precision = -1
		self.zero_fill = False
		self.replaced = -1
		self.validity = False
	def toString(self):
		pass
	def add(self, var, value):
		pass
	def check_validity(self):
		pass

def is_mod(str):
	mod_list = ["hh", "ll", "l", "h", "j", "z", "t", "L"]
	return (str in mod_list)
def is_flag(str):
	flag_list = [" ", "0", "#", "-", "+"]
	return (str in flag_list)
def is_num(str):
	num_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
	return (str in num_list)
def is_id(str):
	id_list = ["d","i","u","o","x","X","f","F","e","E","g","G","a","A","c","s","p","n","%"]
	return (str in id_list)

def fsmsim(current, string, edges, accepting, col = 0, line = 1, tmp = "", token = {}):
	if current in accepting:
		 token[tmp] = (col, line);
		 col += len(tmp)
		 tmp = ""
		 current = 0
		 return fsmsim(current, string, edges, accepting, col, line, tmp, token)
	
	if len(string) == 0:
		return token;
	if (string[0] == "\n"):
		line += 1
		col = 0

	# var expansion

	if is_mod(string[0]):t_str = "MOD"
	elif is_id(string[0]) and current != 0:t_str = "ID"
	elif is_flag(string[0]) and current == 1:t_str = "FLAG"
	elif is_num(string[0]):t_str = "NUM"
	else: t_str = string[0]

	if (current, t_str) in edges:
		destination = edges[(current, t_str)]
		current = destination
		tmp += string[0]
		string = string[1:]
		return fsmsim(current, string, edges, accepting, col, line, tmp, token)
	tmp = ""
	current = 0
	string = string[1:]
	col += 1;
	return fsmsim(current, string, edges, accepting, col, line, tmp, token)


#tests
# "%+         90.34lf"
# "% 12.34hhi"
f_w_p_m_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3,'.') : 4,
	(4, 'NUM') : 5,
	(5, 'NUM') : 5,
	(5, 'MOD') : 6,
	(6, 'ID') : 7
}
f_w_p_m_i_accepting = [7]

string = "op%+90.34lf %+78.43hd"

x = fsmsim(0, string, f_w_p_m_i, f_w_p_m_i_accepting)
for i in x.keys():
	string = string.replace(i, "somethign stupid")
	print (i, string)
print(string)

#tests
# "%+         90.34f"
# "% 12.34i"
f_w_p_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3,'.') : 4,
	(4, 'NUM') : 5,
	(5, 'NUM') : 5,
	(5, 'ID') : 6
}
f_w_p_i_accepting = [6]

#tests
# "%+         90lf"
# "% 12hhi"
f_w_m_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3, 'MOD') : 4,
	(4, 'ID') : 5
}
f_w_m_i_accepting = [5]

#tests
# "%+         90f"
# "% 12i"
f_w_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3, 'ID') : 4
}
f_w_i_accepting = [4]

#tests
# "%+      .34lf"
# "%           .34hhi"
f_p_m_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2,'.') : 3,
	(3, 'NUM') : 4,
	(4, 'NUM') : 4,
	(4, 'MOD') : 5,
	(5, 'ID') : 6
}
f_p_m_i_accepting = [6]

#tests
# "%+      .34f"
# "%           .34i"
f_p_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2,'.') : 3,
	(3, 'NUM') : 4,
	(4, 'NUM') : 4,
	(4, 'ID') : 5
}
f_p_i_accepting = [5]

#tests
# "%+lf"
# "% hhi"
f_m_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'MOD') : 3,
	(3, 'ID') : 4
}
f_m_i_accepting = [4]



#tests
# "%+f"
# "% i"
f_i = {
	(0, '%') : 1,
	(1, 'FLAG') : 2,
	(2, 'ID') : 3
}
f_i_accepting = [3]


#tests
# "%         90.34lf"
# "% 12.34hhi"
w_p_m_i = {
	(0, '%') : 1,
	(1, 'NUM') : 2,
	(2, 'NUM') : 2,
	(2, '.') : 3,
	(3, 'NUM') : 4,
	(4, 'NUM') : 4,
	(4, 'MOD') : 5,
	(5, 'ID') : 6
}
w_p_m_i_accepting = [6]


#tests
# "%         90.34f"
# "% 12.34i"
w_p_i = {
	(0, '%') : 1,
	(1, 'NUM') : 2,
	(2, 'NUM') : 2,
	(2, '.') : 3,
	(3, 'NUM') : 4,
	(4, 'NUM') : 4,
	(4, 'ID') : 5
}
w_p_i_accepting = [5]

#tests
# "%         90.34f"
# "% 12.34i"
w_m_i = {
	(0, '%') : 1,
	(1, 'NUM') : 2,
	(2, 'NUM') : 2,
	(2, 'MOD') : 3,
	(3, 'ID') : 4
}
w_m_i_accepting = [4]

#tests
# "%         90.34f"
# "% 12.34i"
w_i = {
	(0, '%') : 1,
	(1, 'NUM') : 2,
	(2, 'NUM') : 2,
	(2, 'ID') : 3
}
w_i_accepting = [3]

#tests
# "%         .34lf"
# "% .34hi"
p_m_i = {
	(0, '%') : 1,
	(1, '.') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3, 'MOD') : 4,
	(4, 'ID') : 5
}
p_m_i_accepting = [5]

#tests
# "%         .34f"
# "% .34i"
p_i = {
	(0, '%') : 1,
	(1, '.') : 2,
	(2, 'NUM') : 3,
	(3, 'NUM') : 3,
	(3, 'ID') : 4
}
p_i_accepting = [4]

#tests
# "%        lf"
# "% hi"
m_i = {
	(0, '%') : 1,
	(1, 'MOD') : 2,
	(2, 'ID') : 3
}
m_i_accepting = [3]

#tests
# "%        f"
# "% i"
i = {
	(0, '%') : 1,
	(1, 'ID') : 2
}
i_accepting = [2]
