#include "Maze.h"
#include <fstream>

Maze::Maze() : width(0), height(0) {
    width = X_CELLS;
    height = Y_CELLS;
    cells = std::vector<std::vector<int>>{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0},
        {0, 3, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 3, 0},
        {0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::shared_ptr<Intersection> inter_1 = std::make_shared<Intersection>(25, 73);
    std::shared_ptr<Intersection> inter_2 = std::make_shared<Intersection>(105, 73);
    std::shared_ptr<Intersection> inter_3 = std::make_shared<Intersection>(201, 73);
    std::shared_ptr<Intersection> inter_4 = std::make_shared<Intersection>(249, 73);
    std::shared_ptr<Intersection> inter_5 = std::make_shared<Intersection>(345, 73);
    std::shared_ptr<Intersection> inter_6 = std::make_shared<Intersection>(425, 73);
    std::shared_ptr<Intersection> inter_7 = std::make_shared<Intersection>(25, 137);
    std::shared_ptr<Intersection> inter_8 = std::make_shared<Intersection>(105, 137);
    std::shared_ptr<Intersection> inter_9 = std::make_shared<Intersection>(153, 137);
    std::shared_ptr<Intersection> inter_10 = std::make_shared<Intersection>(201, 137);
    std::shared_ptr<Intersection> inter_11 = std::make_shared<Intersection>(249, 137);
    std::shared_ptr<Intersection> inter_12 = std::make_shared<Intersection>(297, 137);
    std::shared_ptr<Intersection> inter_13 = std::make_shared<Intersection>(345, 137);
    std::shared_ptr<Intersection> inter_14 = std::make_shared<Intersection>(425, 137);
    std::shared_ptr<Intersection> inter_15 = std::make_shared<Intersection>(25, 185);
    std::shared_ptr<Intersection> inter_16 = std::make_shared<Intersection>(105, 185);
    std::shared_ptr<Intersection> inter_17 = std::make_shared<Intersection>(153, 185);
    std::shared_ptr<Intersection> inter_18 = std::make_shared<Intersection>(201, 185);
    std::shared_ptr<Intersection> inter_19 = std::make_shared<Intersection>(249, 185);
    std::shared_ptr<Intersection> inter_20 = std::make_shared<Intersection>(297, 185);
    std::shared_ptr<Intersection> inter_21 = std::make_shared<Intersection>(345, 185);
    std::shared_ptr<Intersection> inter_22 = std::make_shared<Intersection>(425, 185);
    std::shared_ptr<Intersection> inter_23 = std::make_shared<Intersection>(153, 233);
    std::shared_ptr<Intersection> inter_24 = std::make_shared<Intersection>(201, 233);
    std::shared_ptr<Intersection> inter_25 = std::make_shared<Intersection>(249, 233);
    std::shared_ptr<Intersection> inter_26 = std::make_shared<Intersection>(297, 233);
    std::shared_ptr<Intersection> inter_27 = std::make_shared<Intersection>(105, 281);
    std::shared_ptr<Intersection> inter_28 = std::make_shared<Intersection>(153, 281);
    std::shared_ptr<Intersection> inter_29 = std::make_shared<Intersection>(297, 281);
    std::shared_ptr<Intersection> inter_30 = std::make_shared<Intersection>(345, 281);
    std::shared_ptr<Intersection> inter_31 = std::make_shared<Intersection>(153, 329);
    std::shared_ptr<Intersection> inter_32 = std::make_shared<Intersection>(297, 329);
    std::shared_ptr<Intersection> inter_33 = std::make_shared<Intersection>(25, 377);
    std::shared_ptr<Intersection> inter_34 = std::make_shared<Intersection>(105, 377);
    std::shared_ptr<Intersection> inter_35 = std::make_shared<Intersection>(153, 377);
    std::shared_ptr<Intersection> inter_36 = std::make_shared<Intersection>(201, 377);
    std::shared_ptr<Intersection> inter_37 = std::make_shared<Intersection>(249, 377);
    std::shared_ptr<Intersection> inter_38 = std::make_shared<Intersection>(297, 377);
    std::shared_ptr<Intersection> inter_39 = std::make_shared<Intersection>(345, 377);
    std::shared_ptr<Intersection> inter_40 = std::make_shared<Intersection>(425, 377);
    std::shared_ptr<Intersection> inter_41 = std::make_shared<Intersection>(25, 425);
    std::shared_ptr<Intersection> inter_42 = std::make_shared<Intersection>(57, 425);
    std::shared_ptr<Intersection> inter_43 = std::make_shared<Intersection>(105, 425);
    std::shared_ptr<Intersection> inter_44 = std::make_shared<Intersection>(153, 425);
    std::shared_ptr<Intersection> inter_45 = std::make_shared<Intersection>(201, 425);
    std::shared_ptr<Intersection> inter_46 = std::make_shared<Intersection>(249, 425);
    std::shared_ptr<Intersection> inter_47 = std::make_shared<Intersection>(297, 425);
    std::shared_ptr<Intersection> inter_48 = std::make_shared<Intersection>(345, 425);
    std::shared_ptr<Intersection> inter_49 = std::make_shared<Intersection>(393, 425);
    std::shared_ptr<Intersection> inter_50 = std::make_shared<Intersection>(425, 425);
    std::shared_ptr<Intersection> inter_51 = std::make_shared<Intersection>(25, 473);
    std::shared_ptr<Intersection> inter_52 = std::make_shared<Intersection>(57, 473);
    std::shared_ptr<Intersection> inter_53 = std::make_shared<Intersection>(105, 473);
    std::shared_ptr<Intersection> inter_54 = std::make_shared<Intersection>(153, 473);
    std::shared_ptr<Intersection> inter_55 = std::make_shared<Intersection>(201, 473);
    std::shared_ptr<Intersection> inter_56 = std::make_shared<Intersection>(249, 473);
    std::shared_ptr<Intersection> inter_57 = std::make_shared<Intersection>(297, 473);
    std::shared_ptr<Intersection> inter_58 = std::make_shared<Intersection>(345, 473);
    std::shared_ptr<Intersection> inter_59 = std::make_shared<Intersection>(393, 473);
    std::shared_ptr<Intersection> inter_60 = std::make_shared<Intersection>(425, 473);
    std::shared_ptr<Intersection> inter_61 = std::make_shared<Intersection>(25, 521);
    std::shared_ptr<Intersection> inter_62 = std::make_shared<Intersection>(201, 521);
    std::shared_ptr<Intersection> inter_63 = std::make_shared<Intersection>(249, 521);
    std::shared_ptr<Intersection> inter_64 = std::make_shared<Intersection>(425, 521);
    std::shared_ptr<Intersection> inter_27_bis = std::make_shared<Intersection>(9, 281);
    std::shared_ptr<Intersection> inter_30_bis = std::make_shared<Intersection>(441, 281);

    // set the neighbors for each intersection
    inter_1->setRight(inter_2);
    inter_1->setDown(inter_7);

    inter_2->setLeft(inter_1);
    inter_2->setRight(inter_3);
    inter_2->setDown(inter_8);

    inter_3->setLeft(inter_2);
    inter_3->setDown(inter_10);

    inter_4->setRight(inter_5);
    inter_4->setDown(inter_11);

    inter_5->setLeft(inter_4);
    inter_5->setRight(inter_6);
    inter_5->setDown(inter_13);

    inter_6->setLeft(inter_5);
    inter_6->setDown(inter_14);

    inter_7->setUp(inter_1);
    inter_7->setRight(inter_8);
    inter_7->setDown(inter_15);

    inter_8->setUp(inter_2);
    inter_8->setLeft(inter_7);
    inter_8->setRight(inter_9);
    inter_8->setDown(inter_16);

    inter_9->setLeft(inter_8);
    inter_9->setRight(inter_10);
    inter_9->setDown(inter_17);

    inter_10->setUp(inter_3);
    inter_10->setLeft(inter_9);
    inter_10->setRight(inter_11);

    inter_11->setUp(inter_4);
    inter_11->setLeft(inter_10);
    inter_11->setRight(inter_12);

    inter_12->setLeft(inter_11);
    inter_12->setRight(inter_13);
    inter_12->setDown(inter_20);

    inter_13->setUp(inter_5);
    inter_13->setLeft(inter_12);
    inter_13->setRight(inter_14);
    inter_13->setDown(inter_21);

    inter_14->setUp(inter_6);
    inter_14->setLeft(inter_13);
    inter_14->setDown(inter_22);

    inter_15->setUp(inter_7);
    inter_15->setRight(inter_16);

    inter_16->setUp(inter_8);
    inter_16->setLeft(inter_15);
    inter_16->setDown(inter_27);

    inter_17->setUp(inter_9);
    inter_17->setRight(inter_18);

    inter_18->setLeft(inter_17);
    inter_18->setDown(inter_24);

    inter_19->setRight(inter_20);
    inter_19->setDown(inter_25);

    inter_20->setUp(inter_12);
    inter_20->setLeft(inter_19);

    inter_21->setUp(inter_13);
    inter_21->setRight(inter_22);
    inter_21->setDown(inter_30);

    inter_22->setUp(inter_14);
    inter_22->setLeft(inter_21);

    inter_23->setRight(inter_24);
    inter_23->setDown(inter_28);

    inter_24->setUp(inter_18);
    inter_24->setLeft(inter_23);
    inter_24->setRight(inter_25);

    inter_25->setUp(inter_19);
    inter_25->setLeft(inter_24);
    inter_25->setRight(inter_26);

    inter_26->setLeft(inter_25);
    inter_26->setDown(inter_29);

    inter_27->setUp(inter_16);
    inter_27->setLeft(inter_27_bis);
    inter_27_bis->setRight(inter_27);
    inter_27_bis->setLeft(inter_30_bis);
    inter_27->setRight(inter_28);
    inter_27->setDown(inter_34);

    inter_28->setUp(inter_23);
    inter_28->setLeft(inter_27);
    inter_28->setDown(inter_31);

    inter_29->setUp(inter_26);
    inter_29->setRight(inter_30);
    inter_29->setDown(inter_32);

    inter_30->setUp(inter_21);
    inter_30->setLeft(inter_29);
    inter_30->setRight(inter_30_bis);
    inter_30_bis->setLeft(inter_30);
    inter_30_bis->setRight(inter_27_bis);
    inter_30->setDown(inter_39);

    inter_31->setUp(inter_28);
    inter_31->setRight(inter_32);
    inter_31->setDown(inter_35);

    inter_32->setUp(inter_29);
    inter_32->setLeft(inter_31);
    inter_32->setDown(inter_38);

    inter_33->setRight(inter_34);
    inter_33->setDown(inter_41);

    inter_34->setUp(inter_27);
    inter_34->setLeft(inter_33);
    inter_34->setRight(inter_35);
    inter_34->setDown(inter_43);

    inter_35->setUp(inter_31);
    inter_35->setLeft(inter_34);
    inter_35->setRight(inter_36);

    inter_36->setLeft(inter_35);
    inter_36->setDown(inter_45);

    inter_37->setRight(inter_38);
    inter_37->setDown(inter_46);

    inter_38->setUp(inter_32);
    inter_38->setLeft(inter_37);
    inter_38->setRight(inter_39);

    inter_39->setUp(inter_30);
    inter_39->setLeft(inter_38);
    inter_39->setRight(inter_40);
    inter_39->setDown(inter_48);

    inter_40->setLeft(inter_39);
    inter_40->setDown(inter_50);

    inter_41->setUp(inter_33);
    inter_41->setRight(inter_42);

    inter_42->setLeft(inter_41);
    inter_42->setDown(inter_52);

    inter_43->setUp(inter_34);
    inter_43->setRight(inter_44);
    inter_43->setDown(inter_53);

    inter_44->setLeft(inter_43);
    inter_44->setRight(inter_45);
    inter_44->setDown(inter_54);

    inter_45->setUp(inter_36);
    inter_45->setLeft(inter_44);
    inter_45->setRight(inter_46);

    inter_46->setUp(inter_37);
    inter_46->setLeft(inter_45);
    inter_46->setRight(inter_47);

    inter_47->setLeft(inter_46);
    inter_47->setRight(inter_48);
    inter_47->setDown(inter_57);

    inter_48->setUp(inter_39);
    inter_48->setLeft(inter_47);
    inter_48->setDown(inter_58);

    inter_49->setRight(inter_50);
    inter_49->setDown(inter_59);

    inter_50->setUp(inter_40);
    inter_50->setLeft(inter_49);

    inter_51->setRight(inter_52);
    inter_51->setDown(inter_61);

    inter_52->setUp(inter_42);
    inter_52->setLeft(inter_51);
    inter_52->setRight(inter_53);

    inter_53->setUp(inter_43);
    inter_53->setLeft(inter_52);

    inter_54->setUp(inter_44);
    inter_54->setRight(inter_55);

    inter_55->setLeft(inter_54);
    inter_55->setDown(inter_62);

    inter_56->setRight(inter_57);
    inter_56->setDown(inter_63);

    inter_57->setUp(inter_47);
    inter_57->setLeft(inter_56);

    inter_58->setUp(inter_48);
    inter_58->setRight(inter_59);

    inter_59->setUp(inter_49);
    inter_59->setLeft(inter_58);
    inter_59->setRight(inter_60);

    inter_60->setLeft(inter_59);
    inter_60->setDown(inter_64);

    inter_61->setUp(inter_51);
    inter_61->setRight(inter_62);

    inter_62->setUp(inter_55);
    inter_62->setLeft(inter_61);
    inter_62->setRight(inter_63);

    inter_63->setUp(inter_56);
    inter_63->setLeft(inter_62);
    inter_63->setRight(inter_64);

    inter_64->setUp(inter_60);
    inter_64->setLeft(inter_63);

    intersections = std::vector<std::shared_ptr<Intersection>>{
        inter_1,      inter_2,     inter_3,  inter_4,  inter_5,  inter_6,  inter_7,  inter_8,
        inter_9,      inter_10,    inter_11, inter_12, inter_13, inter_14, inter_15, inter_16,
        inter_17,     inter_18,    inter_19, inter_20, inter_21, inter_22, inter_23, inter_24,
        inter_25,     inter_26,    inter_27, inter_28, inter_29, inter_30, inter_31, inter_32,
        inter_33,     inter_34,    inter_35, inter_36, inter_37, inter_38, inter_39, inter_40,
        inter_41,     inter_42,    inter_43, inter_44, inter_45, inter_46, inter_47, inter_48,
        inter_49,     inter_50,    inter_51, inter_52, inter_53, inter_54, inter_55, inter_56,
        inter_57,     inter_58,    inter_59, inter_60, inter_61, inter_62, inter_63, inter_64,
        inter_27_bis, inter_30_bis};

    gommes = std::vector<std::shared_ptr<Gomme>>{};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (cells[i][j] == 2) {
                gommes.push_back(std::make_shared<Gomme>(i * CELL_SIZE + CELL_CENTER,
                                                         j * CELL_SIZE + CELL_CENTER, SRC_GUM));
            }
            if (cells[i][j] == 3) {
                gommes.push_back(std::make_shared<Gomme>(i * CELL_SIZE + CELL_CENTER,
                                                         j * CELL_SIZE + CELL_CENTER, SRC_PACGUM));
            }
        }
    }
}

Maze::~Maze() {}

char Maze::getCell(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return -1;
    }
    return cells[row][col];
}

std::vector<std::shared_ptr<Gomme>> Maze::getGommes() const { return gommes; }

void Maze::clearGomme(std::shared_ptr<Gomme> gomme) {
    for (size_t i = 0; i < gommes.size(); i++) {
        if (gommes[i] == gomme) {
            gommes.erase(gommes.begin() + i);
            break;
        }
    }
}

std::vector<std::shared_ptr<Intersection>> Maze::getIntersections() const { return intersections; }

std::shared_ptr<Intersection> Maze::getIntersection(int index) const {
    if (index < 0 || (long unsigned int)index >= intersections.size()) {
        return nullptr;
    }
    return intersections[index];
}

int Maze::getWidth() const { return width; }

int Maze::getHeight() const { return height; }