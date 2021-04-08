#include "Student.cpp"

struct Schoolbook
{
    std::vector<Student*> students;

    void push(std::string f_name, std::string s_name, std::string l_name)
    {
        Student* newstudent = new Student;
        newstudent->names[0] = f_name;
        newstudent->names[1] = s_name;
        newstudent->names[2] = l_name;
        newstudent->number = students.size() + 1;

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
        std::sort(students.begin(), students.end(), by_number);
        output();
    }

    void sort_by_name(int name)
    {
        switch (name)
        {
            case 0:
                std::sort(students.begin(), students.end(), by_f_name);
                break;
            case 1:
                std::sort(students.begin(), students.end(), by_s_name);
                break;
            case 2:
                std::sort(students.begin(), students.end(), by_l_name);
                break;
        }
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