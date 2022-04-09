# 6 - Sparse Matrix and Polynomial Representation

### Sparse Matrix Representation

![Untitled](6%20-%20Sparse%202cab2/Untitled.png)

- A sparse matrix is a type of matrix in which there are more than 0 elements.
- For a matrix of this type, our intention is to store non-zero values inside the matrix.
- There are two methods of storing non-zero elements in this type of matrix:
    - **Coordinate List**
        
        ![spa.png](6%20-%20Sparse%202cab2/spa.png)
        
        - For every non-zero element, we need 1st its row number 2nd its column number, and 3rd the element itself.
        - The first row must be left empty so we can store information about the matrix i.e. its dimensions and non-zero elements.
    - **Compressed Sparse Row**
        - In this method, the sparse matrix is represented using three arrays.
        - 1st array contains non-zero elements (e.g. A[9, 8, 4, 2, 5, 2]), 2nd array contains the cumulative of the number of elements on every single row starting from 0 (e.g. IA[0, 1, 2, 4, 5, 6]) and the 3rd array contains the index number of the non-zero elements in the first array (e.g. JA[5, 2, 1, 4, 6, 3]).

### Addition of two sparse matrices in coordinate list representation

![spar.png](6%20-%20Sparse%202cab2/spar.png)

- The rule of thumb for conducting an addition is they must share the same dimensions in rows and columns.
- Every element of matrix A is added to the corresponding element of matrix B.
- We can represent this using Coordinate List Representation by plugin in the non-zero elements inside a table of Rows, Columns, and Values.

![Screen Shot 2021-10-07 at 15.24.26.png](6%20-%20Sparse%202cab2/Screen_Shot_2021-10-07_at_15.24.26.png)

- Once we have a table containing the information about both matrices we must then plug in the dimensions and update the non-zero elements space once we get the number of elements

![Screen Shot 2021-10-07 at 15.24.51.png](6%20-%20Sparse%202cab2/Screen_Shot_2021-10-07_at_15.24.51.png)

- We need to go through every element of the matrices, so we place variable i on matrix A and variable j on matrix B.
- Rules:
    - Case 1: If aRow < bRow then A add the element and i++
    - Case 2: If aRow and aCol == bRow and bCol then add element and then i + 1 and j + 1.
    - Case 3: If aRow > bRow then add B element and j++
    - Case 4: If aRow == bRow but aCol < bCol then add A element and then i++
    - Case 5: If aRow == bRow but aCol > bCol then add B element and then j++

### **Array Representation of a Sparse Matrix**

- To tackle this topic we must review
- **How to represent**
    - By this, we mean how to represent the row, col, elem table in a program.
- **How to create**
    - In other words, how do we create a sparse matrix in a three-column method table.
- **How to add**
    - Just knowing how to add two matrices.

```cpp
struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int row;
    int col;
    int numOfElements;
    Element *e;
};

void create(struct Sparse *s){
    cout << "Enter dimensions" << endl;
    scanf("%d%d", &s->row, &s->col);
    cout << "Enter the number of non-zero elements" << endl;
    scanf("%d", &s->numOfElements);
    s->e = new Element[s->numOfElements];
    cout << "Enter non-zero elements" << endl;
    for(int i = 0; i < s->numOfElements; i++){
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct Sparse s){
    int k = 0;
    for(int i = 0; i < s.row; i++){
        for(int j = 0; j < s.col; j++){
            if(i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x;
            else
                cout << 0;
        }
        cout << endl;
    }
}

struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    // If aCol is not equal to bCol and aRow is not equal to bRow return nothing
    if(s1->col != s2->col && s1->row != s2->row)
        return NULL;
    
    sum = new Sparse;
    sum->e = new Element[s1->numOfElements + s2->numOfElements];
    
    while(i < s1->numOfElements && j < s2->numOfElements){
        // If aRow < bRow then add the element a and i++
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        // If aRow > bRow then add the element b and j++
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else {
            // If aCol < bCol then add the element a and i++
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            // If aCol > bCol then add the element b and j++
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            // If aRow, aCol == bRow, bCol then add both elements and i++, j++
            else {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    
    for(;i < s1->numOfElements; i++)
        sum->e[k++]=s1->e[i];
    for(;j < s2->numOfElements; j++)
        sum->e[k++]=s2->e[j];
    
    sum->row = s1->row;
    sum->col = s1->col;
    sum->numOfElements = k;
    
    return sum;
}

int main() {
    
    Sparse s1, s2, *s3;
    
    create(&s1);
    create(&s2);
    
    s3 = add(&s1, &s2);
    
    cout << "First Matrix\n";
    display(s1);
    cout << "Second Matrix\n";
    display(s2);
    cout << "Third Matrix\n";
    display(*s3);
    
    return 0;
}

»
Enter dimensions
3 3
Enter the number of non-zero elements
3
Enter non-zero elements
0 0 1
1 1 1
2 2 1
Enter dimensions
3 3
Enter the number of non-zero elements
3
Enter non-zero elements
0 0 2
1 1 2
2 2 2
First Matrix
100
010
001
Second Matrix
200
020
002
Third Matrix
300
030
003
```

- Now that we have an understanding of how to perform addition we can also perform subtraction and multiplication.

### Polynomial Representation

![Screen Shot 2021-10-07 at 15.26.47.png](6%20-%20Sparse%202cab2/Screen_Shot_2021-10-07_at_15.26.47.png)

- An example of a polynomial is the following: $p(x) = 3x^5+2x^4+5x^2+2x+7$
- A polynomial is a collection of terms with a single variable x.
- To understand this topic we need to review:
    - **Polynomial Representation**
        - Polynomials are used to solve various problems, we can use them to represent things.
        - A polynomial is a collection of terms where each has a coefficient, an exponent of x.
        - We can represent this as a list of terms having coefficients and exponents.
        
        ![Screen Shot 2021-10-07 at 15.28.26.png](6%20-%20Sparse%202cab2/Screen_Shot_2021-10-07_at_15.28.26.png)
        
        - **Evaluation of Polynomial**
            - To solve a polynomial we must know the value of x and continue solving the function until we get a final value.
            - This process involves a lot of addition, power, and multiplication. We can solve this with the help of a for-loop.
        - **Addition of two Polynomials**
            - By doing an addition of two polynomials we will generate a new third polynomial.
            - As an example, we will take p1(x)=5x4+2x2+5 and p2(x)=6x4+5x3+9x2+2x+3
            - Remember that the terms with common power will be added. So we must create a third polynomial with a size equivalent to the sum of sizes of p1 and p2.
            - Because size is unknown we can only use a while loop.
            - We need to set three variables at the beginning of the arrays, i, j, and k. Variable i for array1, j for array2, and k for array3.
            - The formulas are as follows:
                - If aExponent == bExponent, then add both coefficients to cCoefficient and cExponent and i++ with j++ and k++
                - If aExponent < bExponent, then take the coefficient from bExponent and j++ and k++.
                - If aExponent > bExponent, then take the coefficient from aExponent and i++ and k++.
        
        ```cpp
        struct Term{
            int coefficient;
            int exponent;
        };
        
        struct Polynomial{
            int numOfElements;
            Term *terms;
        };
        
        void create(struct Polynomial *p){
            cout << "Enter the number of non-zero elements\n";
            scanf("%d", &p->numOfElements);
            p->terms = new Term[p->numOfElements];
            cout << "Enter the terms\n";
            for(int i = 0; i < p->numOfElements; i++)
                scanf("%d%d", &p->terms[i].coefficient, &p->terms[i].exponent);
        }
        
        void display(struct Polynomial p){
            for(int i = 0; i < p.numOfElements; i++)
                printf("%dx%d+\n", p.terms[i].coefficient, p.terms[i].exponent);
        }
        
        Polynomial *add(struct Polynomial *p1, struct Polynomial *p2){
            int i {0}, j {0}, k {0};
            Polynomial *sum = new Polynomial;
            sum->terms = new Term[p1->numOfElements + p2->numOfElements];
            
            while(i < p1->numOfElements && j < p2->numOfElements){
                if (p1->terms[i].exponent > p2->terms[j].exponent)
                    sum->terms[k++] = p1->terms[i++];
                else if (p1->terms[i].exponent < p2->terms[j].exponent)
                    sum->terms[k++] = p2->terms[j++];
                else{
                    sum->terms[k].exponent = p1->terms[i].exponent;
                    sum->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
                }
            }
            for(; i < p1->numOfElements; i++)
                sum->terms[k++] = p1->terms[i];
            for(; j < p2->numOfElements; j++)
                sum->terms[k++] = p2->terms[j];
            sum->numOfElements = k;
            return sum;
        }
        
        int main() {
            Polynomial p1, p2, *p3;
            create(&p1);
            create(&p2);
            display(p1);
            cout << endl;
            create(&p2);
            display(p2);
            cout << endl;
            p3 = add(&p1, &p2);
            display(*p3);
            return 0;
        }
        
        » Enter the number of non-zero elements
        5
        Enter the terms
        4 4
        2 3
        1 2
        4 1
        2 0
        4x4+
        2x3+
        1x2+
        4x1+
        2x0+
        
        Enter the number of non-zero elements
        4
        Enter the terms
        3 3
        2 2
        1 1
        5 0
        3x3+
        2x2+
        1x1+
        5x0+
        
        4x4+5x3+3x2+5x1+7x0+
        ```