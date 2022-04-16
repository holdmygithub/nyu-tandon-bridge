#include<iostream>
#include<vector>

using namespace std;

const int critter_DOODLEBUG = 0, critter_ANT = 1;

class Organism{
    protected:
        int critter;
    public:
        Organism(int critter_type) : critter(critter_type){}
        virtual void move() = 0;
        int get_critter() const{
            return critter;
        }
};

class Ant : public Organism{
    public:
        Ant(): Organism(critter_ANT) {}
        void move(){
            cout<<"HAHA";
        }

};

class Doodlebug : public Organism{
    private:
        int starving;
    public:
        Doodlebug(): Organism(critter_DOODLEBUG), starving(0) {}
        void move(){
            cout<<"HAHA";
        }
        
};

class Grid{
    private:
        vector<vector<Organism*>> cells;
        int timestep,width,height,doodlebug_starving,doodlebug_breed_steps,ant_breed_steps;
        void initialize_grid(int num_ants, int num_doodlebugs){
            int x,y;
            for(int i=0;i<num_doodlebugs;i++){
                x = rand()%width;
                y = rand()%height;
                cells[x][y] = new Doodlebug();
            }

            for(int i=0;i<num_ants;i++){
                x = rand()%width;
                y = rand()%height;
                cells[x][y] = new Ant();
            }


        }


        void showGrid(){
            for(int i=0;i<width;i++)
                for(int j=0;j<height;j++){
                    if(cells[i][j]){
                        if(cells[i][j]->get_critter()==critter_ANT){
                            cout<<"o";

                        }
                        else if(cells[i][j]->get_critter()==critter_DOODLEBUG){
                            cout<<"X";

                        }

                    }
                    else{
                        cout<<"-";
                    }
                }

        }

    public:
        Grid(int inp_height, int inp_width, int inp_num_ants, int inp_num_doodlebugs, int inp_doodlebug_breed_steps, int inp_ant_breed_steps, int inp_doodlebug_starving) : timestep(0), height(inp_height),width(inp_width){
            if((inp_num_ants + inp_num_doodlebugs) > height*width){
                cout<<"Input organisms size is higher than the world";
                exit(1);
            }
            else{ 
                cells.resize(width,vector<Organism*>(height,nullptr)); 
                initialize_grid(inp_num_ants,inp_num_doodlebugs);
                doodlebug_starving = inp_doodlebug_starving;
                doodlebug_breed_steps = inp_doodlebug_breed_steps;
                ant_breed_steps = inp_ant_breed_steps;
            }
        }
};

int main(){
    srand(time(NULL));
    const int WIDTH = 3, HEIGHT = 3, ANTS = 3, DOODLEBUGS = 3, DOODLEBUG_BREED_STEP = 3, ANT_BREED_STEP = 3, DOODLEBUG_STARVING = 3;
    Grid World(WIDTH, HEIGHT, ANTS, DOODLEBUGS, DOODLEBUG_BREED_STEP, ANT_BREED_STEP, DOODLEBUG_STARVING);

    return 0;
}