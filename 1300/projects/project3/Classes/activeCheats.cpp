void activeCheats(bool active_cheats[6]) // Display the names of all cheats in a list with [ACTIVE] next to active cheats
{
    cout << "Cheats:\n"
        << "1. I can see my house from here";
    if (active_cheats[0]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n2. Scrooge McDuck";
    if (active_cheats[1]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n3. 501st";
    if (active_cheats[2]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n4. Super Soldiers";
    if (active_cheats[3]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n5. Zerg Rush";
    if (active_cheats[4]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n6. Cornucopia";
    if (active_cheats[5]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n7. Hoarder";
    if (active_cheats[6]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n";
}