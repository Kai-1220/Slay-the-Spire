import os
cpp_arr=[]
for root, dirs, files in os.walk('src'):
    for file in files:
        cpp_arr.append(os.path.join(root, file))
cpp_arr=[x[4:]for x in cpp_arr]
hpp_arr=[]
for root, dirs, files in os.walk('include'):
    for file in files:
        hpp_arr.append(os.path.join(root, file))
hpp_arr=[x[8:]for x in hpp_arr]
write_str='\n\t'.join(['set(SRC_FILES']+cpp_arr)
write_str+='\n)'
write_str+='\n\n'+'\n\t'.join(['set(INCLUDE_FILES']+hpp_arr)
write_str+='\n)'
write_str+='\n\nset(TEST_FILES\n)'
write_str=write_str.replace('\\','/')
with open('files.cmake','w',encoding='utf-8') as file:
    file.write(write_str)
