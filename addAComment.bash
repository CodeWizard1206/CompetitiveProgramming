# You have a file having Team Members details in the following format

# TeamMember ; Member1 ; Member2

# There are three fields and each field is separated by a ; (semicolon)

# Team Member represents the identification number for the team. Member1 and
# Member2 represents the names of the team members.

# write the unix command to add a comment as "--> To be removed !" (excluding
# quotes) after the pattern "Him or him or HIM" as part of it (the member name).

# Ex. Names like Hima or Himashree or Shreehim or Rijuhimak. If found any records with
# the name having the mentioned pattern (him/Him/HIM...) then add the comment after
# the respective record.

# If there are no records with the pattern looking for( as part of the member name).
# then display the input records as is.

# Any of the member name (Member1 or Member2) can have the given pattern. For more
# clarify, please refer the sample input and output below.

# The input file with the data(testcase input/customized input) in the format
# mentioned, automatically supplied as command line argument when you run the script
# /command, you have written. hence you don't need to worry / work on, "How to bring
# the file to your script"?

# You just need to assume that a file is supplied to your script and read the file,
# which is supplied as command line argument and process the data in the file towards
# the given requirement.

# You can use shell variables (e.g. $0,$1,$2) whichever is applicable for your
# requirement to provide the command line argument

# Sample Testcase1
# Input :
# TeamMember;Member1;Member2
# 101;Lovely;Himshikha
# 102;Loveleena;Mayum
# 103;Farida;Reeta
# 104;Ruby;Himadri
# 105;Geetika;Himparna

# Output:
# TeamMember;Member1;Member2
# 101;Lovely;Himshikha
# --> To be removed !
# 102;Loveleena;Mayum
# 103;Farida;Reeta
# 104;Ruby;Himadri
# --> To be removed !
# 105;Geetika;Himparna
# --> To be removed !

# Sample Testcase2
# Input:
# TeamMember;Member1;Member2
# 101;Lovely;Shikha
# 102;Loveleena;Mauri
# 103;Farida;Reeta
# 104;Ruby;Madri
# 105;Himshikha;Himparna
# 106;Rituhimashri;Badal

# Output:
# TeamMember;Member1;Member2
# 101;Lovely;Shikha
# 102;Loveleena;Mauri
# 103;Farida;Reeta
# 104;Ruby;Madri
# 105;Himshikha;Himparna
# --> To be removed !
# 106;Rituhimashri;Badal
# --> To be removed !

# ANSWER :

# read
# awk 'BEGIN{FS=";";}
# {
#     if(index($2,"Him")!=0
#         ||index($2,"him")!=0
#         ||index($2,"HIM")!=0
#         ||index($3,"Him")!=0
#         ||index($3,"him")!=0
#         ||index($3,"HIM")!=0)
#     {
#         print($1";",$2";",$3);
#         print("--> To be removed !");
#     }
#     else
#     {
#         print($1";",$2";",$3);
#     }
# }
# END{}'

read
awk 'BEGIN{FS=";";}
{if(index($2,"Him")!=0||index($2,"him")!=0||index($2,"HIM")!=0||index($3,"Him")!=0||index($3,"him")!=0||index($3,"HIM")!=0){print($1";",$2";",$3);print("--> To be removed !");}else{print($1";",$2";",$3);}}
END{}'