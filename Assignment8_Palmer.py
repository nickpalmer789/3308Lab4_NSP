def main():
	#Get the dictionary
	abbreviations = createDictionary("textToEnglish.csv")
	
	#Contunue asking the user for abbreviations until they say quit
	keepAsking = True
	while(keepAsking):
		
		#Get the user's input
		userInput = raw_input("Please enter abbreviations: ")
		
		#Check the user's input
		if(userInput == "quit"):
			keepAsking = False
		else:
			#Split the user's input into the different words
			inputList = userInput.split(" ")
			for item in inputList:
				
				#Check if the keys are in the dictionary
				if item in abbreviations:
					print(abbreviations[item]),
				else:
					#Print NF if the key isn't in the dictionary
					print("NF"),
			print
	
	

def createDictionary(filename):
	#Create the empty dictionary
	dict = {}
	
	#Create the file
	myFile = open(filename, "r")
	
	#Loop through the lines in the file
	for line in myFile.read().splitlines():
		#Split the line
		data = line.split(",")
		#New entry in dictionary
		dict[data[0]] = data[1]
		
	return dict



if __name__ == "__main__":
	main()
