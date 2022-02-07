import os
from turtle import bgcolor
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

# import sys
# try:
#     directory_name=sys.argv[1:]
#     print(directory_name)
# except:
#     print('Please pass directory_name')
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-e","--ext", help="Provide extention name i.e. text,pdf") 	# naming it "path"
args = parser.parse_args()
extension_name=None
if not args.ext:
    parser.error('--ext, -e is required. For help -h')
extension_name="."+str(args.ext)
curr_dir_path = os.getcwd()

for root, subdirs, files in os.walk(curr_dir_path):
    for current_file in files:
        if(current_file.endswith(extension_name)):
            current_folder =  root.split("\\")[-1]
            current_file_path = os.path.join(root,current_file)
            new_name = current_folder.lower()+"-"+current_file
            new_name_path = os.path.join(root,new_name)
            os.rename(current_file_path, new_name_path)
            print(bcolors.OKGREEN+f"Renamed: {current_file} ----> {new_name}"+bcolors.ENDC)