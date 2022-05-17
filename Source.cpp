#include <iostream>
#include <vector>

const double factor = 1.2473309;
struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};
stats selection_sort(std::vector<int>& data)
{
    stats st;
    size_t key;
    for (size_t i = 0; i < data.size() - 1; i++)
    {
        key = 0;
        for (size_t j = 0; j < data.size() - i; j++)
        {
            st.comparison_count++;
            if (data[key] < data[j])//максимальный элемент
            {
                key = j;
            }
        }
        if (data[key] != data[data.size() - 1 - i])//меняем со значением на месте максимального элемента
        {
            int tmp = data[key];
            data[key] = data[data.size() - 1 - i];
            data[data.size() - 1 - i] = tmp;
            st.copy_count++;
        }
    }
    return st;
};

stats sheker_sort(std::vector<int>& data)
{
    stats st;
    int left = 0, right = data.size() - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        st.comparison_count++;
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (data[i] > data[i + 1]) // если следующий элемент меньше текущего,
            {
                st.copy_count++;         // меняем их местами
                int tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (data[i - 1] > data[i]) // если предыдущий элемент больше текущего,
            {
                st.copy_count++;    // меняем их местами
                int tmp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = tmp;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    return st;
};
stats comb_sort(std::vector<int>& data)
{
    stats st;
    int step = data.size() - 1; // шаг сортировки

    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1) {
        for (int i = 0; i + step < data.size(); i++) {

            st.comparison_count++;
            if (data[i] > data[i + step]) {

                st.copy_count++;         // меняем их местами
                int tmp = data[i];
                data[i] = data[i + step];
                data[i + step] = tmp;
               
            }
        }
        step /= factor;
    }
    return st;
};
int main()
{
    stats st;
    std::vector<int> vec1 = { 4,5,-8,3,-7,-5,1,0,9,6 };
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    st = selection_sort(vec1);
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    std::cout << "Selection sort" << std::endl;
    std::cout << "Number of comparisons:" << st.comparison_count << std::endl;
    std::cout << "Number of copies:" << st.copy_count << std::endl;

    std::cout << std::endl;

    std::vector<int> vec2 = { 4,-5,3,10,-4,-6,8,-10,1,6 };
    for (auto i = vec2.begin(); i != vec2.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    st = sheker_sort(vec2);
    for (auto i = vec2.begin(); i != vec2.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    std::cout << "Sheker sort" << std::endl;
    std::cout << "Number of comparisons:" << st.comparison_count << std::endl;
    std::cout << "Number of copies:" << st.copy_count << std::endl;

    std::cout << std::endl;

    std::vector<int> vec3 = { 4,5,-8,3,-7,-5,1,0,9,6 };
    for (auto i = vec3.begin(); i != vec3.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    st = comb_sort(vec3);
    for (auto i = vec3.begin(); i != vec3.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    std::cout << "Comb sort" << std::endl;
    std::cout << "Number of comparisons:" << st.comparison_count << std::endl;
    std::cout << "Number of copies:" << st.copy_count << std::endl;
    return 0;
}
