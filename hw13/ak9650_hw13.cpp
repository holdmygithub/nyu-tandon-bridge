//program written by ak9650, Ashwin K Raghu (NYU Tandon Bridge 24 week winter 2022)

#include<iostream>
#include<vector>

using namespace std;

const int critter_DOODLEBUG = 0, critter_ANT = 1;
const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
const int LEN_NEIGHBOR = 4;

class Organism{
    protected:
        int critter;
        bool accessed_recently;
        int breeding;
    public:
        Organism(int critter_type) : critter(critter_type), accessed_recently(false), breeding(0){}
        virtual void move() = 0;
        virtual void resetStarving(){};
        virtual int getStarving() const{
            return 0;
        }
        
        int get_critter() const{
            return critter;
        }

        bool recently_accessed() const{
            return accessed_recently;
        }

        int getBreeding() const{
            return breeding;
        }

        void resetBreeding(){
            breeding = 0;
        }
        void resetMove(){
            accessed_recently = false;
        }
};

class Ant : public Organism{
    public:
        Ant(): Organism(critter_ANT){}
        void move(){
            breeding+=1;
            accessed_recently = true;
        }

};

class Doodlebug : public Organism{
    private:
        int starving;
    public:
        Doodlebug(): Organism(critter_DOODLEBUG), starving(0){}
        void resetStarving(){
            starving = 0;
        }

        int getStarving() const{
            return starving;
        }

        void move(){
            breeding+=1;
            starving+=1;
            accessed_recently = true;
        }
        
};

class Grid{
    private:
        vector<vector<Organism*>> cells;
        int timestep,width,height,doodlebug_starving,doodlebug_breed_steps,ant_breed_steps;
        void initialize_grid(int num_ants, int num_doodlebugs){
            int x,y;
            while(num_doodlebugs>0){
                x = rand()%width;
                y = rand()%height;
                if(!cells[x][y]){
                    cells[x][y] = new Doodlebug();
                    num_doodlebugs--;
                }
            }

            while(num_ants>0){
                x = rand()%width;
                y = rand()%height;
                if(!cells[x][y]){
                    cells[x][y] = new Ant();
                    num_ants--;
                }
            }
        }
        bool inbounds(int x,int y){
            int inbound = false;
            if((x<width) && (x>=0) && (y<height) && (y>=0))
                inbound= true;
            return inbound;
        }

        void starve(){
            for(int x=0;x<width;x++)
                for(int y=0;y<height;y++){
                    if((cells[x][y]) && (cells[x][y]->get_critter()==critter_DOODLEBUG) && (cells[x][y]->getStarving()>=doodlebug_starving)){
                        delete cells[x][y];
                        cells[x][y] = nullptr;
                    }
                }
        }
        void moveDoodleBugs();
        void moveAnts();
        void breed();



    public:
        Grid(int inp_height, int inp_width, int inp_num_ants, int inp_num_doodlebugs, int inp_doodlebug_breed_steps, int inp_ant_breed_steps, int inp_doodlebug_starving) : timestep(0), height(inp_height),width(inp_width){
            if((inp_num_ants + inp_num_doodlebugs) > height*width){
                cout<<"Input organisms size is higher than the 2D grid. No space to place organisms.";
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

        void showGrid(){
            cout<<"Timestep: "<<timestep<<endl;
            for(int x=0;x<width;x++){
                for(int y=0;y<height;y++){
                    if(cells[x][y]){
                        if(cells[x][y]->get_critter()==critter_ANT){
                            cout<<"o ";

                        }
                        else if(cells[x][y]->get_critter()==critter_DOODLEBUG){
                            cout<<"X ";

                        }

                    }
                    else{
                        cout<<"- ";
                    }
                }
                cout<<endl;
            }

        }

        void resetMovements(){
            for(int x=0;x<width;x++)
                for(int y=0;y<height;y++){
                    if(cells[x][y]){
                        cells[x][y]->resetMove();
                    }
                }
            
        }
        void nextTimeStep(){
            timestep++;
            moveDoodleBugs();
            moveAnts();
            breed();
            starve();
            resetMovements();
            showGrid();
        }
};

void Grid::moveAnts(){
    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++){
            if(cells[x][y]==nullptr){
                continue;
            }
            else if((!(cells[x][y]->recently_accessed())) && (cells[x][y]->get_critter()==critter_ANT)){
                int neighbor = rand()%4,shift_x,shift_y;
                if(neighbor==LEFT){
                    shift_x = 0;
                    shift_y = -1;
                }
                else if(neighbor==RIGHT){
                    shift_x = 0;
                    shift_y = 1;
                }
                else if(neighbor==UP){
                    shift_x = -1;
                    shift_y = 0;
                }
                else if(neighbor==DOWN){
                    shift_x = 1;
                    shift_y = 0;
                }
                else{
                    shift_x = 0;
                    shift_y = 0;
                }

                cells[x][y]->move();
                int x_new = x + shift_x, y_new = y+shift_y;
                if(inbounds(x_new,y_new)&&(!cells[x_new][y_new])){
                    cells[x_new][y_new] = cells[x][y];
                    cells[x][y] = nullptr;
                }
            }
            else{
                continue;
            }
        }
}

void Grid::breed(){
    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++){
            if(cells[x][y]==nullptr){
                continue;
            }
            else{
                int breed_flag = false;
                if((cells[x][y]->get_critter()==critter_ANT) && (cells[x][y]->getBreeding()>=ant_breed_steps)){
                    int neighbors_x[] =  {x,x,x+1,x-1}, neighbors_y[] =  {y-1,y+1,y,y};
                    for(int k=0;k<LEN_NEIGHBOR;k++){
                        if(inbounds(neighbors_x[k],neighbors_y[k]) && (!breed_flag) &&(!cells[neighbors_x[k]][neighbors_y[k]])){
                            cells[neighbors_x[k]][neighbors_y[k]] = new Ant();
                            cells[x][y]->resetBreeding();
                            breed_flag = true;
                        }
                        
                    }
                }
                else if((cells[x][y]->get_critter()==critter_DOODLEBUG) && (cells[x][y]->getBreeding()>=doodlebug_breed_steps)){

                    int neighbors_x[] =  {x,x,x+1,x-1}, neighbors_y[] =  {y-1,y+1,y,y};
                    for(int k=0;k<LEN_NEIGHBOR;k++){
                        if(inbounds(neighbors_x[k],neighbors_y[k]) && (!breed_flag) &&(!cells[neighbors_x[k]][neighbors_y[k]])){
                            cells[neighbors_x[k]][neighbors_y[k]] = new Doodlebug();
                            cells[x][y]->resetBreeding();
                            breed_flag = true;
                        }
                        
                    }
                }

                }
            }

}

void Grid::moveDoodleBugs(){
    int shift_x, shift_y;
    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++){
            if(cells[x][y]==nullptr){
                continue;
            }
            else if((!(cells[x][y]->recently_accessed())) && (cells[x][y]->get_critter()==critter_DOODLEBUG)){

                int neighbors_x[] =  {x,x,x+1,x-1}, neighbors_y[] =  {y-1,y+1,y,y};
                bool ate_ant = false;

                cells[x][y]->move();
                for(int k=0;k<LEN_NEIGHBOR;k++){
                    if(inbounds(neighbors_x[k],neighbors_y[k])){
                        if((!ate_ant)&&(cells[neighbors_x[k]][neighbors_y[k]]!=nullptr)&&(cells[neighbors_x[k]][neighbors_y[k]]->get_critter()==critter_ANT)){
                            delete cells[neighbors_x[k]][neighbors_y[k]];
                            cells[neighbors_x[k]][neighbors_y[k]] = cells[x][y];
                            cells[x][y] = nullptr;
                            cells[neighbors_x[k]][neighbors_y[k]]->resetStarving();
                            ate_ant = true;
                        }
                        else{
                            continue;
                        }

                    }
                    else{
                        continue;
                    }

                }
                if(!ate_ant){
                    int neighbor = rand()%4;
                    if(neighbor==LEFT){
                        shift_x = 0;
                        shift_y = -1;
                    }
                    else if(neighbor==RIGHT){
                        shift_x = 0;
                        shift_y = 1;
                    }
                    else if(neighbor==UP){
                        shift_x = -1;
                        shift_y = 0;
                    }
                    else if(neighbor==DOWN){
                        shift_x = 1;
                        shift_y = 0;
                    }
                    else{
                        shift_x = 0;
                        shift_y = 0;
                    }

                    int x_new = x + shift_x, y_new = y+shift_y;
                    if(inbounds(x_new,y_new)&&(!cells[x_new][y_new])){
                        cells[x_new][y_new] = cells[x][y];
                        cells[x][y] = nullptr;
                    }
                }
            }
            else{
                continue;
            }
            

        }

    
}

int main(){
    srand(0);
    const int WIDTH = 20, HEIGHT = 20, ANTS = 100, DOODLEBUGS = 5, DOODLEBUG_BREED_STEP = 8, ANT_BREED_STEP = 3, DOODLEBUG_STARVING = 3;
    Grid world(WIDTH, HEIGHT, ANTS, DOODLEBUGS, DOODLEBUG_BREED_STEP, ANT_BREED_STEP, DOODLEBUG_STARVING);
    world.showGrid();
    cout<<endl<<"Press Enter key to move to next timestep or any other key to exit.";
    while(cin.get()=='\n'){
        world.nextTimeStep();
        cout<<endl<<"Press Enter key to move to next timestep or any other key to exit."<<endl;
    }
    return 0;
}