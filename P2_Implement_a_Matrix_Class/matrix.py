def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(size):
    mat = [[0 for j in range(size)]for i in range(size)]
    for i in range(size):
        for j in range(size):
            if i == j:
                mat[i][j] = 1
    return Matrix(mat)

class Matrix:
    def __init__(self, mat):
        self.rows = len(mat)
        self.columns = len(mat[0])
        self.matrix = [[mat[i][j] for j in range(self.columns)]for i in range(self.rows)]
    
    
    def determinant(self):
        if self.rows != self.columns or self.rows > 2 :
            raise(f"matrix needs to be 2x2 yours is {self.rows}x{self.columns}")
            return
        elif self.rows == 2:
            return self.matrix[0][0]*self.matrix[1][1] - self.matrix[0][1]*self.matrix[1][0]
        else:
            return self.matrix[0][0]
    
    
    
    def trace(self):
        if self.rows == self.columns:
            tr = 0;
            for i in range(self.rows):
                for j in range(self.columns):
                    if i == j:
                        tr += self.matrix[i][j]
            return tr;
    
    
    def T(self):
        mat = [[0 for i in range(self.rows)]for j in range(self.columns)]
        
        for i in range(self.rows):
            for j in range(self.columns):
                mat[j][i] = self.matrix[i][j]
        return Matrix(mat)
    
    
    
    def inverse(self):
        if self.rows != self.columns or self.rows > 2 :
            raise(f"matrix needs to be 2x2 yours is {self.rows}x{self.columns}")
            return
        elif(self.rows == 2):
            tr = self.trace()
            det = self.determinant()
            iden = identity(2)
            tr_iden = Matrix([[tr * iden.matrix[i][j] for j in range(self.columns)] for i in range(self.rows)])
            mat = tr_iden - self

            return Matrix([[(1/det) * mat.matrix[i][j] for j in range(mat.columns)] for i in range(mat.rows)])
        else:
            return Matrix([[1/self.matrix[0][0]]])
    
    
    
    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.matrix:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s
    
    
    
    def __add__(self, other):
        if self.rows == other.rows and self.columns == other.columns:
            return Matrix([[self.matrix[i][j] + other.matrix[i][j] for j in range(self.columns)]for i in range(self.rows)])
        else:
            raise("matrices must have same size")
        
        
                       
    
    
    def __sub__(self, other):
        if self.rows == other.rows and self.columns == other.columns:
            return Matrix([[self.matrix[i][j] - other.matrix[i][j] for j in range(self.columns)]for i in range(self.rows)])
        else:
            raise("matrices must have same size")
    
    
    def __mul__(self, other):
        if self.columns == other.rows:
            val = 0
            mat = [[0 for j in range(other.columns)]for i in range(self.rows)]
            
            for i in range(self.rows):
                for j in range(other.columns):
                    for k in range(self.columns):
                        val +=self.matrix[i][k]*other.matrix[k][j]
                    mat[i][j] = val
                    val = 0
            
            return Matrix(mat)
        else:
            raise("matrix 1 columns not equal to matrix 2 rows")
            
        
    
    def __neg__(self):
        return Matrix([[-self.matrix[i][j] for j in range(self.columns)]for i in range(self.rows)])
   
    def __rmul__(self, other):
        return Matrix([[other * self.matrix[i][j] for j in range(self.columns)]for i in range(self.rows)])