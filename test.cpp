#include "pch.h"
#include "Barca.h"
#include "Porto.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>
TEST(Barca, CostruttoreVuoto) {
    Barca b; //test costruttore vuoto 
    b = Barca();
    ASSERT_TRUE(b.getNome() == "" && b.getNazione() == "???" && b.getLunghezza() == 0 && b.getStazza() == 0 && b.isVela() == false);
}
TEST(Barca, CostruttoreConParametri ) {

    Barca b1;
    b1= Barca("Zeus", "italia", 20, 100, true);
    //test costruttori con parametri della classe Barca
    ASSERT_TRUE(b1.getNome() == "Zeus" && b1.getNazione() == "italia" && b1.getLunghezza() == 20 && b1.getStazza() == 100 && b1.isVela() == true);

}
TEST(Barca, TestGet) {

    Barca b;
    b = Barca("Luna Rossa", "italia", 200, 400, true);
    //test metodi get classe barca
    ASSERT_EQ("Luna Rossa", b.getNome());
    ASSERT_EQ("italia", b.getNazione());
    ASSERT_EQ(200, b.getLunghezza());
    ASSERT_EQ(400, b.getStazza());
}
TEST(Barca, TestSet) { //test metodi set Barca 

    Barca b;
    b.setNome("Amerigo Vespucci");
    EXPECT_TRUE(b.getNome() == "Amerigo Vespucci");
    b.setNome("Burundi");
    EXPECT_TRUE(b.getNome() == "Burundi");
    b.setLunghezza(30);
    EXPECT_FALSE(b.getLunghezza() == 45);
    b.setLunghezza(88);
    EXPECT_FALSE(b.getLunghezza() == 250);
}
TEST(Porto, costruttore)
{//Porto metodo costruttore
    bool occupato[100];
    Porto p();
    for (int i = 0; i < 100; i = i + 1)
    {
        ASSERT_FALSE(occupato[i]==false);
    }
}
TEST(Porto, TestSetGeT)
{
    //Porto metodi set e get 
    Porto p;
    p = Porto();
    p.setTariffa_motore(45.50);
    EXPECT_TRUE(45.50, p.getTariffa_motore);
    p.setTariffa_vela(512.54);
    EXPECT_TRUE(512.54, p.getTariffa_vela);
}
TEST(Porto, arrivo) {       //test metodo arrivo

    Barca b1 = Barca("Veliero Fantasma", "Jamaica", 10, 100, true);
    Porto p;
    p.arrivo(b1);

    ASSERT_TRUE(p.occupato[51-1] == true);

}
TEST(Porto, partenza) {   //test partenza

    Barca b1 = Barca("Luna Rossa", "Italia", 10, 100, true);
    Porto p;
    p.arrivo(b1);
    p.setTariffa_vela(12);
    float conta = 2 * p.getTariffa_vela() * b1.getLunghezza();
    ASSERT_TRUE(p.partenza(51, 2) == conta);
}
TEST(Porto, modificaImbarcazione)
{ //test metodo modifica
    int posto = 51;
    Barca b1 = Barca("Veliero Fantasma", "Jamaica", 10, 100, true);
    Porto p;
    p.arrivo(b1);
    p.modifica(posto, "Luna Rossa", "italia", 200, 400);
    ASSERT_FALSE(p.barche[posto].getNome() == "Veliero Fantasma" && p.barche[posto].getNazione() == "Jamaica" && p.barche[posto].getLunghezza() == 10 && p.barche[posto].getStazza() == 100);
}
TEST(Porto, cerca)
{ //test metodo cerca
    Porto p;
    Barca b[10];
    int conta = p.cerca(1, 10, b);
    ASSERT_TRUE(conta == 0);
}
TEST(Porto, informazioni)
{//test metodo informazioni 
    Porto p;
    Barca b1("Perla Nera", "USA", 13, 70, true);
    p.arrivo(b1);
    Barca b2 = p.informazioni(51);
    ASSERT_TRUE(b2.getNome() != "");

}
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}