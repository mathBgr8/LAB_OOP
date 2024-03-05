#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../include/npc.hpp"
#include "../include/druid.hpp"
#include "../include/knight.hpp"
#include "../include/elf.hpp"
#include "../include/obs.hpp"


TEST(NPC_Fights, Test1) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0);

    bool knight_kills_elf = knight->accept(elf);
    ASSERT_TRUE(knight_kills_elf);
}

TEST(NPC_Fights, Test2) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);

    bool elf_kills_knight = elf->accept(knight);
    ASSERT_TRUE(elf_kills_knight);
}

TEST(NPC_Fights, Test3) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(0, 0);

    bool elf_kills_druid = elf->accept(druid);
    ASSERT_TRUE(elf_kills_druid);
}

TEST(NPC_Fights, Test5) {
    std::shared_ptr<NPC> druid1 = std::make_shared<Druid>(0, 0);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(0, 0);

    bool druid_kills_druid = druid->accept(druid1);
    ASSERT_TRUE(druid_kills_druid);
}

TEST(NPC_Fights, Test4) {
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);

    bool druid_kills_knight = druid->accept(knight);
    ASSERT_FALSE(druid_kills_knight);
}

TEST(NPC_Fights, Test6) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(1, 1);
    std::shared_ptr<NPC> elf1 = std::make_shared<Elf>(0, 0);

    bool elf_kills_elf = elf->accept(elf1);
    ASSERT_FALSE(elf_kills_elf);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
