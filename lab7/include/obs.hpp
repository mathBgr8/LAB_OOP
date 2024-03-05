#include "npc.hpp"

#define LOG "log.txt"

// Text Observer
class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::cout << std::endl
                      << "Murder --------" << std::endl;
            attacker->print(std::cout);
            defender->print(std::cout);
        }
    }
};



class FileObserver : public IFightObserver
{
private:
    std::string filename;
    std::ofstream fs;
    FileObserver(std::string filename) : filename(filename) 
    {
        fs.open(filename);
    };
    ~FileObserver() {
        fs.flush();
        fs.close();
    }
public:
    static std::shared_ptr<IFightObserver> get(std::string filename)
    {
        static FileObserver instance(filename);
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
        if(win) 
        {
            fs << std::endl
                      << "Murder --------" << std::endl;
            attacker->print(fs);
            defender->print(fs);
            fs.flush();
        }
    }
};