//#include <gtest/gtest.h>
//
//#include "../utils/HeadersConnector.h"
//#include "../World.h"

// displayInstancesAround() test case
TEST(WorldTest, DISPLAY_INSTANCES_AROUND)
{
World world(10, 10);
Instance* attacker = new Knight(&world, 5, 5, '1');
world.setInstanceOnMap(attacker, attacker->getPosX(), attacker->getPosY());

Instance* defender1 = new Knight(&world, 4, 4, '2');
world.setInstanceOnMap(defender1, defender1->getPosX(), defender1->getPosY());

Instance* defender2 = new Swordsman(&world, 5, 6, '2');
world.setInstanceOnMap(defender2, defender2->getPosX(), defender2->getPosY());

std::vector<Instance*> unitsAround = world.displayInstancesAround(attacker);

EXPECT_EQ(unitsAround.size(), 2);
EXPECT_EQ(unitsAround[0], defender1);
EXPECT_EQ(unitsAround[1], defender2);
}

// attackUnit test case
TEST(WorldTest, ATTACK_OTHER_UNIT)
{
World world(10, 10);
Instance* attacker = new Knight(&world, 5, 5, '1');
world.setInstanceOnMap(attacker, attacker->getPosX(), attacker->getPosY());

Instance* defender = new Swordsman(&world, 4, 4, '2');
world.setInstanceOnMap(defender, defender->getPosX(), defender->getPosY());

int initialHP = defender->getHitPoints();

world.attackUnit(attacker, defender);

EXPECT_LT(defender->getHitPoints(), initialHP);
EXPECT_GT(defender->getHitPoints(), 0);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}