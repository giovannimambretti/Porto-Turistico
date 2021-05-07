
#include "pch.h"
#include "Barca.h"
#include "Porto.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

    //test classe Barca




TEST(Barca, CostruttoreVuoto) {    //test costruttore senza parametri

    Barca b; 
    b = Barca();
    ASSERT_TRUE(b.getNome() == "" && b.getNazione() == "???" && b.getLunghezza() == 0 && b.getStazza() == 0 && b.isVela() == false);
}


TEST(Barca, CostruttoreConParametri) { //test costruttore con parametri

    Barca b1;
    b1 = Barca("Zeus", "italia", 20, 100, true);
    //test costruttori con parametri della classe Barca
    ASSERT_TRUE(b1.getNome() == "Zeus" && b1.getNazione() == "italia" && b1.getLunghezza() == 20 && b1.getStazza() == 100 && b1.isVela() == true);

}


TEST(Barca, Get) {       //test metodi Get

    Barca b;
    b = Barca("Luna Rossa", "italia", 200, 400, true);

    ASSERT_EQ("Luna Rossa", b.getNome());
    ASSERT_EQ("italia", b.getNazione());
    ASSERT_EQ(200, b.getLunghezza());
    ASSERT_EQ(400, b.getStazza());
}

TEST(Barca, Set) {   //test metodi Set con il false

    Barca b;
 
    b.setNome("Apollo");
    ASSERT_FALSE("PROVA" == b.getNome());
    b.setLunghezza(9);
    ASSERT_FALSE(10 == b.getLunghezza());
    b.setNazione("Usa");
    ASSERT_FALSE("canada" == b.getNazione());
    b.setStazza(130);
    ASSERT_FALSE(330 == b.getStazza());
    

}


        // TEST classe Porto

TEST(Porto, arrivo) {       //test arrivo

    Barca b1 = Barca("Eva", "Usa", 10, 100, true);
    Porto p;
    p.arrivo(b1);

    ASSERT_TRUE(p.occupato[50] == true);

}

TEST(Porto, partenza) {   //test partenza

    Barca b1 = Barca("Eva", "Usa", 10, 100, true);
    Porto p;
    p.arrivo(b1);

    ASSERT_TRUE(p.partenza(51 , 2) != NULL);
}


TEST(Porto, modifica_Imbarcazione)  // test modifica
{
    int posto = 51;
    Barca b1 = Barca("Veliero Fantasma", "Jamaica", 10, 100, true);
    Porto p;
    p.arrivo(b1);
    p.modifica(posto, "Luna Rossa", "italia", 200, 400);
    ASSERT_FALSE(p.barche[posto].getNome() == "Veliero Fantasma" && p.barche[posto].getNazione() == "Jamaica" && p.barche[posto].getLunghezza() == 10 && p.barche[posto].getStazza() == 100);
}

TEST(Porto, cerca) { // test cerca posto 
    Porto p;
    Barca b[10];
    int conta = p.cerca(1, 10, b);
    ASSERT_TRUE(conta == 0 );


}

TEST(Porto, TestSetGeT) //Test metodi set e get 
{
    
    Porto p;
    p = Porto();
    p.setTariffa_motore(45.50);
    EXPECT_TRUE(45.50, p.getTariffa_motore);
    p.setTariffa_vela(512.54);
    EXPECT_TRUE(512.54, p.getTariffa_vela);
}

TEST(Porto, informazioni) // test metodo informazioni
{
    Porto p;
    Barca b1("Perla Nera", "Caraibi", 13, 70, true);
    p.arrivo(b1);
    Barca b2 = p.informazioni(51);

    ASSERT_TRUE(b2.getNome() != " " && b2.getNazione() == "");
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
