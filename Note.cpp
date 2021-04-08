#include "help_funk.cpp"

struct Note
{
    std::vector<int> notes;
    int term_note = 0, sum = 0;
    double average = 0;

    void push(int x)
    {
        notes.push_back(x);
        sum += x;
        average = (double)(sum) / notes.size();
    }

    void erase(int x)
    {
        int pos = notes.size();
        for (int i = 0; i < notes.size(); ++i)
        {
            if (notes[i] == x)
            {
                pos = i;
                break;
            }
        }

        if (pos == notes.size())
        {
            std::cout << "No note found\n";
            return;
        }

        std::swap(notes[pos], notes[notes.size() - 1]);
        notes.pop_back();
        sum -= x;
        average = (double)(sum) / notes.size();
    }

    //TODO
    void output()
    {
        for (int note : notes)
        {
            std::cout << note << ' ';
        }
        std::cout << "\t(" << average << ")";
        tn(term_note);
    }
};