#include "matrixaddblock.h"
#include "../types/types.h"

MatrixAddBlock::MatrixAddBlock(Graph &g)
    : BlockBase(g, MAT_ADD, "2D Matrix Addition",
    {
        InPort(*this, mat2(), "A"),
        InPort(*this, mat2(), "B")
    },
    {
        OutPort(*this, mat2(), "Out")
    }
    ){}

void MatrixAddBlock::Compute()
{
    this->Output(0)["m11"] = this->Input(0)["m11"] + this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] + this->Input(1)["m12"];
    this->Output(0)["m21"] = this->Input(0)["m21"] + this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] + this->Input(1)["m22"];
}