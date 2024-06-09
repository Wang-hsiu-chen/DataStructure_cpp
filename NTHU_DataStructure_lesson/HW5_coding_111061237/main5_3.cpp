#include "3_AOEnetwork.cpp"

int main()
{
    LinkedGraph g1(9);
    g1.ChangeToMetrix();
    g1.Setup1();
    g1.TopologicalOrder();
    g1.TimeOfEvents();
    g1.TimeOfActivies();
}
