#include <iostream>
#include <vector>
#include <utility> // for std::pair

std::pair<int,int> get_dimensions(const std::vector<std::vector<int>>& matrix)
{
    std::pair<int,int> dimensions{};
    bool to_get_y{true};

    for (const auto& row : matrix)
    {
        if (to_get_y)
        {
            for (const auto& col : row)
            {
                dimensions.second++;
            }
            to_get_y = false;
        }
            dimensions.first++;
    }
    return dimensions;
}

 bool can_be_multiplied(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
    auto dimensions_matrix1{get_dimensions(matrix1)};
    auto dimensions_matrix2{get_dimensions(matrix2)};
    return dimensions_matrix1.second == dimensions_matrix2.first;
}

class Matrix
{   
    public:
        std::vector<std::vector<int>>& get_matrix()
        {
            return m_data;
        }

        void print_matrix() const
        {
            bool first{true};
            for (auto &row : m_data)
            {
                first = true;
                for (auto &col : row)
                {
                    if (first) { std::cout << "| "; }
                    std::cout << col << " ";
                    first = false;
                }
                std::cout << "|" << std::endl;
            }
        }

        void set_matrix(const std::vector<std::vector<int>>& matrix)
        {
            m_data = matrix;
        }

        bool friend operator==(const Matrix& matrix1, const Matrix& matrix2);

        Matrix& operator*=(Matrix& matrix)
        {
            if (!can_be_multiplied(m_data, matrix.get_matrix()))
            {
                std::cerr << "The matrices can't be multiplied!" << std::endl;
                return (*this);
            }

            std::pair<int,int> dimensions1{get_dimensions(m_data)};
            std::pair<int,int> dimensions2{get_dimensions(matrix.get_matrix())};

            std::vector<std::vector<int>> temp(dimensions1.first, std::vector<int>(dimensions2.second, 0));

            for (int i = 0; i < dimensions1.first; i++)
            {
                for (int j = 0; j < dimensions2.second; j++)
                {
                    temp[i][j] = 0;
                    for (int k = 0; k < dimensions1.second; k++)
                    {
                        temp[i][j] += m_data[i][k]*matrix.get_matrix()[k][j];
                    }
                }
            }
            m_data = temp;
            return (*this);
        }

        Matrix& operator*=(const std::vector<std::vector<int>>& matrix)
        {
            if (!can_be_multiplied(m_data, matrix))
            {
                std::cerr << "The matrices can't be multiplied!" << std::endl;
                return (*this);
            }

            std::pair<int,int> dimensions1{get_dimensions(m_data)};
            std::pair<int,int> dimensions2{get_dimensions(matrix)};

            std::vector<std::vector<int>> temp(dimensions1.first, std::vector<int>(dimensions2.second, 0));

            for (int i = 0; i < dimensions1.first; i++)
            {
                for (int j = 0; j < dimensions2.second; j++)
                {
                    temp[i][j] = 0;
                    for (int k = 0; k < dimensions1.second; k++)
                    {
                        temp[i][j] += m_data[i][k]*matrix[k][j];
                    }
                }
            }
            m_data = temp;
            return (*this);
        }

        Matrix& operator*=(const int& number)
        {
            for (auto& row : m_data)
            {
                for (auto& col : row)
                {
                    col *= number;
                }
            }
            return (*this);
        }

    private:
        std::vector<std::vector<int>> m_data;
};

Matrix operator*(Matrix& matrix1, Matrix& matrix2)
{
    Matrix temp_matrix;

    if (!can_be_multiplied(matrix1.get_matrix(), matrix2.get_matrix()))
    {
        std::cerr << "The matrices can't be multiplied!" << std::endl;
        return temp_matrix; ///
    }

    std::pair<int,int> dimensions1{get_dimensions(matrix1.get_matrix())};
    std::pair<int,int> dimensions2{get_dimensions(matrix2.get_matrix())};

    std::vector<std::vector<int>> temp(dimensions1.first, std::vector<int>(dimensions2.second, 0));

    for (int i = 0; i < dimensions1.first; i++)
    {
        for (int j = 0; j < dimensions2.second; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < dimensions1.second; k++)
            {
                temp[i][j] += matrix1.get_matrix()[i][k]*matrix2.get_matrix()[k][j];
            }
        }
    }

    temp_matrix.set_matrix(temp);
    return temp_matrix;

}
bool operator==(const Matrix& matrix1, const Matrix& matrix2)
{
    return matrix1.m_data == matrix2.m_data;
}

Matrix operator-(const Matrix& matrix)
{
    auto temp{matrix};
    for (auto& row : temp.get_matrix())
    {
        for (auto& col : row)
        {
            col = -col;
        }
    }
    return temp;
}

std::ostream& operator<<(std::ostream& s, Matrix& matrix)
{
    for (const auto& row : matrix.get_matrix())
    {
        for (const auto& col : row)
        {
            s << col << " ";
        }
        s << std::endl;
    }
    return s;
}

int main()
{
    // Matrix matrix;

    // matrix.set_matrix({{1,2,3}, {4,5,6}});
    // matrix.print_matrix();

    // Matrix matrix1;
    // matrix1.set_matrix({{1,2,3}, {4,5,6}});

    // ==============
    // TEST OPERTOR==
    // ==============
    // bool test = matrix == matrix1;
    // std::cout << test;

    // ==============
    // TEST OPERATOR-
    // ==============
    // Matrix matrix2{-matrix};
    // matrix2.print_matrix();

    // ==============
    // TEST OPERATOR<<
    // ==============
    // std::cout << matrix;

    // ==============
    // TEST get_dimensions
    // ==============
    // auto dimensions = get_dimensions(matrix.get_matrix());
    // std::cout << "(" << dimensions.first << ", " << dimensions.second << ")" << std::endl;

    // ==============
    // TEST 1 operator*=
    // ==============
    // Matrix matrix4;
    // matrix4.set_matrix({{1,2,3}, {3,2,1}});

    // Matrix matrix5;
    // matrix5.set_matrix({{2,1}, {4,2}, {3,2}, {5,5}});

    // matrix4 *= matrix5;

    // ==============
    // TEST 2 operator*=
    // // ==============
    // Matrix matrix6;
    // matrix6.set_matrix({{1,2,3}, {2,3,1}});

    // Matrix matrix7;
    // matrix7.set_matrix({{1,2}, {1,1}, {3,2}});

    // std::cout << (matrix6 *= matrix7) << std::endl;

    // ==============
    // TEST operator*
    // ==============
    // Matrix matrix8, matrix9;
    // matrix8.set_matrix({{1,2}, {2,2}, {1,1}});
    // matrix9.set_matrix({{1,1,1}, {2,1,2}});

    // std::cout << (matrix8 * matrix9) << std::endl;
    return 0;
}