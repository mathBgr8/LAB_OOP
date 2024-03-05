#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

// type for npcs
struct NPC;
struct Druid;
struct Knight;
struct Elf;
using set_t = std::set<std::shared_ptr<NPC>>;



enum NpcType
{
    Unknown,
    DruidType,
    KnightType,
    ElfType
};

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC>
{
    private:
        std::mutex mtx;

        NpcType type;

        bool alive{true};
        int x{0};
        int y{0};


        std::vector<std::shared_ptr<IFightObserver>> observers;

    public:

        std::vector<int> sh = {-1, 1};


        NPC(NpcType t, int _x, int _y);
        NPC(NpcType t, std::istream &is);
    
        void subscribe(std::shared_ptr<IFightObserver> observer);
        void fight_notify(const std::shared_ptr<NPC> defender,bool win);

        virtual bool is_Druid() const;
        virtual bool is_knight() const;
        virtual bool is_Elf() const ;


        virtual bool is_close(const std::shared_ptr<NPC> &other);
        void move(int max_x, int max_y);
        bool is_alive();
        void must_die();
        std::pair<int, int> position();
        NpcType get_type();
        virtual int get_attack_range() = 0;
        virtual std::pair<int, int> get_shift() = 0;

        virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
        virtual bool fight(std::shared_ptr<Druid> other) = 0;
        virtual bool fight(std::shared_ptr<Knight> other) = 0;
        virtual bool fight(std::shared_ptr<Elf> other) = 0;


        virtual void print(std::ostream& os) = 0;
        virtual void save(std::ostream &os);
        friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};