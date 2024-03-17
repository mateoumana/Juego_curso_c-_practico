#ifndef CELLS_H
#define CELLS_H

class Cells{
    private:

    protected:
        int index;

    public:
        Cells();
        ~Cells();
        //Get and Set
        int getCell(); //Leer el index del mapa desde un archivo txt
        void setCell(char cell);
};

#endif