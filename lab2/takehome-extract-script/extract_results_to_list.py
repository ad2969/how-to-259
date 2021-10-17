from itertools import groupby

numlist = []

with open ('long_sample_result.txt', 'rt') as myfile:
    for myline in myfile:
        number = myline.split()[8]
        if(number.isdigit()):
            numlist.append(int(number))

with open ('long_sample_result_list.txt', 'w') as outputfile:
    outputfile.write('[' + ','.join(str(num) for num in numlist) + ']')
