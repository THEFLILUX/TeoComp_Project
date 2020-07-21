#include <iostream>
#include "afd.cpp"
#include <vector>
#include <ctime>

using namespace std;



int main(){
    


    //EJEMPLO https://www.youtube.com/watch?v=qgeARf15F6k

    /*state<int>* q0 = new state<int>('A',true,true);
    state<int>* q1 = new state<int>('B',true,false);
    state<int>* q2 = new state<int>('C',true,false);
    state<int>* q3 = new state<int>('D',true,false);
    state<int>* q4 = new state<int>('E',false,false);
    
    q0->set_t(0, q1);
    q0->set_t(1, q2);
    q1->set_t(0, q1);
    q1->set_t(1, q3);
    q2->set_t(0, q1);
    q2->set_t(1, q4);
    q3->set_t(0, q1);
    q3->set_t(1, q4);
    q4->set_t(0, q4);
    q4->set_t(1, q4);
    */

    //EJEMPLO PAPER
    

    state<int>* q0 = new state<int>('A',false,true);
    state<int>* q1 = new state<int>('B',false,false);
    state<int>* q2 = new state<int>('C',true,false);
    state<int>* q3 = new state<int>('D',true,false);
    state<int>* q4 = new state<int>('E',true,false);
    state<int>* q5 = new state<int>('F',false,false);

    q0->set_t(0, q1);
    q0->set_t(1, q2);
    q1->set_t(0, q0);
    q1->set_t(1, q3);
    q2->set_t(0, q4);
    q2->set_t(1, q5);
    q3->set_t(0, q4);
    q3->set_t(1, q5);
    q4->set_t(0, q4);
    q4->set_t(1, q5);
    q5->set_t(0, q5);
    q5->set_t(1, q5);
    

    //EJEMPLO https://www.gatevidyalay.com/minimization-of-dfa-minimize-dfa-example/
    
    /*state<int>* q0 = new state<int>('A',false,true);
    state<int>* q1 = new state<int>('B',false,false);
    state<int>* q2 = new state<int>('C',false,false);
    state<int>* q3 = new state<int>('D',false,false);
    state<int>* q4 = new state<int>('E',true,false);
    

    q0->set_t(0, q1);
    q0->set_t(1, q2);
    q1->set_t(0, q1);
    q1->set_t(1, q3);
    q2->set_t(0, q1);
    q2->set_t(1, q2);
    q3->set_t(0, q1);
    q3->set_t(1, q4);
    q4->set_t(0, q1);
    q4->set_t(1, q2);
    */
    
    //EJEMPLO  8 estados
    /*state<int>* q0 = new state<int>('A',false,true);
    state<int>* q1 = new state<int>('B',false,false);
    state<int>* q2 = new state<int>('C',true,false);
    state<int>* q3 = new state<int>('D',false,false);
    state<int>* q4 = new state<int>('E',false,false);
    state<int>* q5 = new state<int>('F',false,false);
    state<int>* q6 = new state<int>('G',false,false);
    state<int>* q7 = new state<int>('H',false,false);
    q0->set_t(0, q1);
    q0->set_t(1, q5);
    q1->set_t(0, q6);
    q1->set_t(1, q2);
    q2->set_t(0, q0);
    q2->set_t(1, q2);
    q3->set_t(0, q2);
    q3->set_t(1, q6);
    q4->set_t(0, q7);
    q4->set_t(1, q5);
    q5->set_t(0, q2);
    q5->set_t(1, q6);
    q6->set_t(0, q6);
    q6->set_t(1, q4);
    q7->set_t(0, q6);
    q7->set_t(1, q2);
    */
    
    
    DFA<int> minimizacion(q0);

    unsigned t0, t1_hopcroft, t1_moore, t1_tf;
    t0=clock();

    //HOPCROFT
    minimizacion.Paso1();
    minimizacion.Paso2();
    t1_hopcroft = clock();
    minimizacion.print();
    double time = (double(t1_hopcroft-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time*1000 << endl;

    //MOORE
    /*minimizacion.Paso1();
    minimizacion.Moore();
    t1_moore = clock();
    minimizacion.print();
    double time = (double(t1_moore-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time*1000 << endl;*/

    return 0;
}
