#include "pch.h"
#include "Barca.h"
#include "Porto.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>
TEST(Barca, Costruttore) {
    Barca b;
    b = Barca();
    ASSERT_TRUE(b.getNome() == "" && b.getNazione() == "???" && b.getLunghezza() == 0 && b.getStazza() == 0 && b.isVela() == false);
}
TEST(Barca, CostruttoreConParametri) {

    Barca b1;
    b1 = Barca("Luca", "Paolo", 12, 32, true);
    ASSERT_TRUE(b1.getNome() == "Luca" && b1.getNazione() == "Paolo" && b1.getLunghezza() == 12 && b1.getStazza() == 32 && b1.isVela() == true);

}
TEST(Barca, TestGet) {

    Barca b;
    b = Barca("Gabriele", "Marco", 21, 54, true);
    ASSERT_EQ("Gabriele", b.getNome());
    ASSERT_EQ("Marco", b.getNazione());
    ASSERT_EQ(21, b.getLunghezza());
    ASSERT_EQ(54, b.getStazza());
}
TEST(Barca, TestSet) { 

    Barca b;
    b.setNome("Mario");
    EXPECT_TRUE(b.getNome() == "Mario");
    b.setNome("Antonio");
    EXPECT_TRUE(b.getNome() == "Antonio");
    b.setLunghezza(26);
    EXPECT_FALSE(b.getLunghezza() == 85854);
    b.setLunghezza(58);
    EXPECT_FALSE(b.getLunghezza() == 6295);
}
TEST(Porto, costruttore)
{
    bool occupato[100];
    Porto p();
    for (int i = 0; i < 100; i = i + 1)
    {
        ASSERT_FALSE(occupato[i] == false);
    }
}
TEST(Porto, TestSetGeT)
{
    Porto p;
    p = Porto();
    p.setTariffa_motore(52.20);
    EXPECT_TRUE(52.20, p.getTariffa_motore);
    p.setTariffa_vela(54.12);
    EXPECT_TRUE(54.12, p.getTariffa_vela);
}
TEST(Porto, arrivo) { 

    Barca b1 = Barca("Luigi", "Germania", 10, 100, true);
    Porto p;
    p.arrivo(b1);

    ASSERT_TRUE(p.occupato[51 - 1] == true);

}
TEST(Porto, partenza) {  

    Barca b1 = Barca("Luigi", "Germania", 10, 100, true);
    Porto p;
    p.arrivo(b1);
    p.setTariffa_vela(12);
    float conta = 2 * p.getTariffa_vela() * b1.getLunghezza();
    ASSERT_TRUE(p.partenza(51, 2) == conta);
}
TEST(Porto, modificaImbarcazione)
{ 
    int posto = 51;
    Barca b1 = Barca("Veliero Fantasma", "Jamaica", 10, 100, true);
    Porto p;
    p.arrivo(b1);
    p.modifica(posto, "Luna Rossa", "italia", 200, 400);
    ASSERT_FALSE(p.barche[posto].getNome() == "Luna Rossa" && p.barche[posto].getNazione() == "italia" && p.barche[posto].getLunghezza() == 400 && p.barche[posto].getStazza() == 200);
}
TEST(Porto, cerca)
{
    Porto p;
    Barca b[15];
    int conta = p.cerca(1, 15, b);
    ASSERT_TRUE(conta == 0);
}
TEST(Porto, informazioni)
{ 
    Porto p;
    Barca b1("Concordia", "Italia", 22, 1200, true);
    p.arrivo(b1);
    Barca b2 = p.informazioni(51);
    ASSERT_TRUE(b2.getNome() != "");

}
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
