//
//  main.cpp
//  HashTables
//
//  Created by jim bailey on 4/19/21.
//

#include <iostream>

#define TEST_BASE // always define this if testing any base
#define TEST_BASE_FIND
//#define TEST_BASE_REMOVE
//#define TEST_BASE_DISPLAY
//#define TEST_BASE_GROW

#define TEST_ADV // always define this if testing any advanced
//#define TEST_ADV_FIND
//#define TEST_ADV_REMOVE
//#define TEST_ADV_DISPLAY
//#define TEST_THINK // test adv grow

#ifdef TEST_BASE
#include "StringHash.hpp"
#endif
#ifdef TEST_ADV
#include "ChainHash.hpp"
#endif

int main()
{
#ifdef TEST_BASE
    const int BASE_SIZE = 5;
    std::string baseWords[BASE_SIZE] = { "maple", "spruce", "oak", "cedar", "cherry"};

    std::cout << "\nStringHash tests\n" << std::endl;
#ifdef TEST_BASE_FIND
    std::cout << "Testing addItem and findItem\n" << std::endl;
    StringHash baseFind;

    for (int i = 0; i < BASE_SIZE; i++)
    {
        baseFind.addItem(baseWords[i]);
    }
    std::cout << baseFind.displayTable() << std::endl;
    std::cout << "Should find maple and not apple" << std::endl;
    std::cout << " maple" << (baseFind.findItem("maple") ? " " : " not ") << "found" << std::endl;
    std::cout << " a" << (baseFind.findItem("a") ? " " : " not ") << "found" << std::endl;
    std::cout << " apple" << (baseFind.findItem("apple") ? " " : " not ") << "found" << std::endl;


    std::cout << "\nDone testing addItem and findItem\n" << std::endl;
#endif // TEST_BASE_FIND
#ifndef TEST_BASE_REMOVE
    std::cout << "Testing addItem, findItem, and removeItem\n" << std::endl;
    StringHash baseRemove;

    for (int i = 0; i < BASE_SIZE; i++)
    {
        baseRemove.addItem(baseWords[i]);
    }
    std::cout << "Should find maple and then not find maple" << std::endl;
    std::cout << " maple" << (baseRemove.findItem("maple") ? " " : " not ") << "found" << std::endl;
    baseRemove.removeItem("maple");
    std::cout << " maple" << (baseRemove.findItem("maple") ? " " : " not ") << "found" << std::endl;
    std::cout << "Should find spruce" << std::endl;
    std::cout << " spruce" << (baseRemove.findItem("spruce") ? " " : " not ") << "found" << std::endl;
    std::cout << baseRemove.displayTable() << std::endl;
    std::cout << "\nDone testing addItem, findItem, and removeItem\n" << std::endl;
#endif // TEST_BASE_REMOVE
#ifndef TEST_BASE_DISPLAY
    std::cout << "Testing addItem, findItem, removeItem, and display\n" << std::endl;
    StringHash baseList;

    for (int i = 0; i < BASE_SIZE; i++)
    {
        baseList.addItem(baseWords[i]);
    }
    baseList.removeItem("apple");
    std::cout << "Should be cedar cherry maple spruce 6(_empty_) oak" << std::endl;
    std::cout << baseList.displayTable();

    std::cout << "\nDone testing addItem, findItem, removeItem, and display\n" << std::endl;
#endif // TEST_BASE_DISPLAY
#ifndef TEST_BASE_GROW
    std::cout << "Testing growing StringHash\n" << std::endl;
    const int BASE_EXTRA = 3;
    std::string baseExtraWords[BASE_EXTRA] = { "bear", "pony", "cow" };

    StringHash baseGrow;

    for (int i = 0; i < BASE_SIZE; i++)
    {
        baseGrow.addItem(baseWords[i]);
    }

    for (int i = 0; i < BASE_EXTRA; i++)
    {
        baseGrow.addItem(baseExtraWords[i]);
    }
    std::cout << "After growing the list should be " << std::endl;
    std::cout << "_empty_ cherry _empty_ _empty_ _empty_ cow _empty_ _empty_ "
        << "_empty_ pony cedar _empty_ _empty_ maple spruce "
        << "_empty_ _empty_ _empty_ _empty_ _empty_ bear oak" << std::endl;
    std::cout << "The order might differ, but contents should not\n" << std::endl;
    std::cout << baseGrow.displayTable() << std::endl;

    std::cout << "Now testing find and remove after growing" << std::endl;
    std::cout << "Should find maple and then not find maple" << std::endl;
    std::cout << " maple" << (baseGrow.findItem("maple") ? " " : " not ") << "found" << std::endl;
    baseGrow.removeItem("maple");
    std::cout << " maple" << (baseGrow.findItem("maple") ? " " : " not ") << "found" << std::endl;
    std::cout << "Should find spruce" << std::endl;
    std::cout << " spruce" << (baseGrow.findItem("spruce") ? " " : " not ") << "found" << std::endl;

    std::cout << "\nDone testing growing StringHash\n" << std::endl;
#endif // TEST_BASE_GROW
#endif // TEST_BASE

#ifdef TEST_ADV
    const int ADV_SIZE = 10;
    std::string advWords[ADV_SIZE] = { "dog", "cat", "ape", "cow", "frog", "fish", "goat", "bear", "deer", "elk" };

    std::cout << "\nChainHash tests\n" << std::endl;
#ifndef TEST_ADV_FIND
    std::cout << "Testing addItem and findItem\n" << std::endl;
    ChainHash advFind;

    for (int i = 0; i < ADV_SIZE; i++)
    {
        advFind.addItem(advWords[i]);
    }
    std::cout << "Should find goat and not horse" << std::endl;
    std::cout << "goat" << (advFind.findItem("goat") ? " " : " not ") << "found" << std::endl;
    std::cout << "horse" << (advFind.findItem("horse") ? " " : " not ") << "found" << std::endl;
    std::cout << advFind.displayTable();
    std::cout << "\nDone testing addItem and findItem\n" << std::endl;
#endif // TEST_ADV_FIND

#ifndef TEST_ADV_REMOVE
    std::cout << "Testing addItem, findItem, and removeItem\n" << std::endl;
    ChainHash advRemove;

    for (int i = 0; i < ADV_SIZE; i++)
    {
        advRemove.addItem(advWords[i]);
    }
    std::cout << "Should find goat and then not find goat" << std::endl;
    std::cout << "goat" << (advRemove.findItem("goat") ? " " : " not ") << "found" << std::endl;
    advRemove.removeItem("goat");
    std::cout << "goat" << (advRemove.findItem("goat") ? " " : " not ") << "found" << std::endl;

    std::cout << "\nDone testing addItem, findItem, and removeItem\n" << std::endl;
#endif // TEST_ADV_REMOVE

#ifndef TEST_ADV_DISPLAY
    std::cout << "Testing addItem, findItem, removeItem, and display\n" << std::endl;
    ChainHash advList;

    for (int i = 0; i < ADV_SIZE; i++)
    {
        advList.addItem(advWords[i]);
    }

    //advList.removeItem("goat");
    std::cout << "Should be: \n_empty_\ndeer frog\nfish cow\n"
        << "goat\ndog\nbear\nelk ape cat" << std::endl;
    std::cout << "The order might differ, but contents should not\n" << std::endl;
    std::cout << advList.displayTable();

    std::cout << "\nDone testing addItem, findItem, removeItem, and display\n" << std::endl;
#endif // TEST_ADV_DISPLAY

#ifndef TEST_THINK
    std::cout << "Testing thinking problem (growing ChainHash)\n" << std::endl;
    const int ADV_EXTRA = 6;
    std::string advExtraWords[ADV_EXTRA] = { "apple", "pine", "fir", "oak", "maple", "fig" };

    ChainHash advGrow;

    for (int i = 0; i < ADV_SIZE; i++)
    {
        advGrow.addItem(advWords[i]);
    }
    for (int i = 0; i < ADV_EXTRA; i++)
    {
        advGrow.addItem(advExtraWords[i]);
    }
    std::cout << "\nAfter growing the list should have 13 rows " << std::endl;
    std::cout << "and include apple, pine, fir, oak, maple, fig, dog," << std::endl;
    std::cout << "cat, ape, cow, frog, fish, goat, bear, deer, elk \n" << std::endl;
    std::cout << advGrow.displayTable();

    std::cout << "\nDone testing growing StringHash\n" << std::endl;
#endif // TEST_THINK
#endif // TEST_ADV

    return 0;
}