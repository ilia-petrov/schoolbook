#include "Student.cpp"

struct Schoolbook
{
    private int size = 0;
    
    std::vector<Student*> students;

    void push(std::string f_name, std::string s_name, std::string l_name)
    {
        Student* newstudent = new Student;
        newstudent->names[0] = f_name;
        newstudent->names[1] = s_name;
        newstudent->names[2] = l_name;
        newstudent->number = size;
        
        ++ size;

        students.push_back(newstudent);
    }

    void output()
    {
        for (Student* student : students)
        {
            student->output();
        }
        std::cout << '\n';
    }

    void sort_by_number()
    {
        std::sort(students.begin(), students.end(), [](Student* a, Student* b)
                                                      {
                                                          return a->number < b->number;
                                                      });
        output();
    }

    void sort_by_name(int name)
    {
        std::sort(students.begin(), students.end(), [&, name](Student* a, Student* b)
                                                             {
                                                                 return a->names[name] < b->names[name];
                                                             });
        output();
    }

    int find_number(int n, bool is)
    {
        int forreturn = students.size();

        for (int i = 0; i < students.size(); ++ i)
        {
            if (students[i]->number == n)
            {
                if (is)
                {
                    students[i]->output();
                }

                forreturn = i;
            }
        }

        if (forreturn == students.size())
        {
            std::cout << "No student\n";
        }

        return forreturn;
    }

    int find_name(std::string str, int name, bool is)
    {
        int forreturn = students.size();

        for (int i = 0; i < students.size(); ++ i)
        {
            if (students[i]->names[name] == str)
            {
                if (is)
                {
                    students[i]->output();
                }

                forreturn = i;
            }
        }

        if (forreturn == students.size())
        {
            std::cout << "No student\n";
        }

        return forreturn;
    }

    void erase_number(int n)
    {
        int forerase = find_number(n, 0);

        if (forerase == students.size())
        {
            return;
        }

        std::swap(students[forerase], students[students.size() - 1]);
        students.pop_back();
    }

    void erase_name(std::string str, int name)
    {
        int forerase = find_name(str, name, 0);

        if (forerase == students.size())
        {
            return;
        }

        std::swap(students[forerase], students[students.size() - 1]);
        students.pop_back();
    }
};
