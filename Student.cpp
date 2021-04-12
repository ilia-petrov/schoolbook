#include "Note.cpp"

struct Student
{
    std::string names[3];
    int number;
    std::map<std::string, Note*> subjects;
    double average = 0, term_average = 0;

    void push(std::string sub, int n)
    {
        auto where = subjects.find(sub);
        if (where == subjects.end())
        {
            Note* newnote = new Note;
            where = subjects.insert({ sub, newnote }).first;
        }

        where->second->push(n);
    }

    void push_term(std::string sub, int n)
    {
        auto where = subjects.find(sub);
        if (where == subjects.end())
        {
            Note* newnote = new Note;
            where = subjects.insert({ sub, newnote }).first;
        }
        where->second->term_note = n;
    }

    void compute_average()
    {
        if (subjects.size() == 0)
        {
            return;
        }

        int all_sum = 0, all_cnt = 0, term_sum = 0, term_cnt = 0;
        for (auto it = subjects.begin(); it != subjects.end(); it ++)
        {
            all_cnt += it->second->notes.size();
            all_sum += it->second->sum;
            term_sum += it->second->term_note;
            term_cnt += (it->second->term_note ? 1 : 0);
        }

        average = (double)all_sum / all_cnt;
        if (term_cnt) {
            term_average = (double)term_sum / term_cnt;
        }
    }

    //TODO
    void output()
    {
        this->compute_average();
        std::cout << "# " << number << ' ' << names[0] << ' ' << names[1] << ' ' << names[2] << ":\t" << average;
        tn(term_average);
        for (auto it = subjects.begin(); it != subjects.end(); it++)
        {
            std::cout << '\t' << it->first << ":\t";
            it->second->output();
        }
    }

    void erase_note(std::string sub, int x)
    {
        auto where = subjects.find(sub);
        if (where == subjects.end())
        {
            std::cout << "No subject found\n";
            return;
        }

        where->second->erase(x);
    }

    void erase_term_note(std::string sub)
    {
        auto where = subjects.find(sub);
        if (where == subjects.end())
        {
            std::cout << "No subject found";
            return;
        }

        where->second->term_note = 0;
    }

    void erase_subject(std::string sub)
    {
        subjects.erase(sub);
    }
};
