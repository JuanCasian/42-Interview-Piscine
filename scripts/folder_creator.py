import os, sys

args = sys.argv
if (len(args) < 3):
    print("Specify folder and number of folders to be created")
    exit()
max_folder = int(args[2])
for i in range(max_folder + 1):
	os.system("mkdir {}/ex{:02d}".format(args[1], i))
	# os.system("touch {}/ex{:02d}/bigo".format(args[1], i))
	print("creating folder: {}/ex{:02d}".format(args[1], i))
	# print("Creatinfg file: {}/ex{:02d}/bigo".format(args[1], i))
print("ready")
