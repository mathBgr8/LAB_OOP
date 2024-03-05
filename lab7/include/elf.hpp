#pragma once
#include "npc.hpp"

struct Elf : public NPC
{
private:
    int attack_range = 50;
    std::pair<int, int> shift = {10, 10};
public:
    Elf(int x, int y);
    Elf(std::istream &is);

    void print(std::ostream& os) override;

    void save(std::ostream &os) override;
    bool is_Elf() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    virtual int get_attack_range() override;
    virtual std::pair<int, int> get_shift() override;

    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &knight);
};