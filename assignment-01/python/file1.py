class matrix(object):
    """docstring for matrix"""
    def __init__(self, row, col):
        self.mat = []
        self.rows = row
        self.columns = col
        for i in range(0,self.rows):
            self.mat.append([])
            for j in range(0, self.columns):
                self.mat[i].append(0)

    def setDeepCopy(self,valMat):
        self.mat = []
        for i in range(0,self.rows):
            self.mat.append([])
            for j in range(0, self.columns):
                self.mat[i].append(valMat[i][j])


    def setShalowCopy(self,valMat):
    	self.mat = valMat




    def __str__(self):
        returnStr = ""
        for i in range(0,self.rows):
            for j in range(0,self.columns):
                returnStr += str(self.mat[i][j])
                returnStr += " "
            if i+1 != self.rows:
                returnStr += "\n"
        return returnStr 

    

    def countZeroInRow(self,arr):
    	count = 0
    	for i in range(0, self.columns):
    		if arr[i] != 0:
    			return count
    		else:
    			count += 1
    	return count


    def checkEchelonForm(self):
        if self.rows == self.columns == 0:
            return False
        elif self.rows == 1:
            return True
        else:
            lowestNumberOfZeros = -1
            for i in range(0, self.rows):
                numberOfZeros = self.countZeroInRow(self.mat[i])
                if lowestNumberOfZeros < numberOfZeros:
                    lowestNumberOfZeros = numberOfZeros
                elif lowestNumberOfZeros == numberOfZeros:
                    if numberOfZeros == self.columns:
                        continue
                    else:
                        return False
                else:
                    return False
            return True



    def checkReduceEchelonForm(self):
        if self.rows == self.columns == 0:
            return False
        elif self.rows == 1:
            return True
        else:
            lowestNumberOfZeros = -1
            for i in range(0, self.rows):
                numberOfZeros = 0
                for j in range(0, self.columns):
                    if self.mat[i][j] == 0:
                        numberOfZeros += 1
                    elif self.mat[i][j] == 1:
                        for k in range(0, self.rows):
                            if id(self.mat[k][j]) == id(self.mat[i][j]) or self.mat[k][j] == 0:
                                continue
                            else:
                                return False
                        break
                    else:
                        return False
                if lowestNumberOfZeros < numberOfZeros:
                    lowestNumberOfZeros = numberOfZeros
                elif lowestNumberOfZeros == numberOfZeros:
                    if numberOfZeros == self.columns:
                        continue
                    else:
                        return False
                else:
                    return False
            return True


    
m = matrix(3,3)
t = [[1,0,0],[0,1,0],[0,0,1]]
m.setDeepCopy(t)
# print(m.checkEchelonForm())
print(m.checkReduceEchelonForm())
print(m)