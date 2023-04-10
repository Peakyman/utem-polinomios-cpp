#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

const double Tolerancia = 0.1;

int main(){
    int Grado;
    double dr,ds;
    
    cout<<"==================="<<endl;
	cout<<"Integrantes:"<<endl;
	cout<<"Nicolas Garay"<<endl;
	cout<<"Cristobal Diaz"<<endl;
	cout<<"==================="<<endl;

    cout << "Ingrese el grado del polinomio: "; //ingreso de grado del polinomio
    cin >> Grado;

    double coeficientes[Grado+1];
    cout<<"Ingrese los coeficientes del polinomio"<<endl; //ingreso de los coeficientes del polinomio

    for (int i = 0; i <= Grado; i++) {
        cout<<endl<<"Ingrese el coeficiente de x^"<<i<<" :";
        cin>>coeficientes[i];
    }
    cout<<endl;

    cout<<"polinomio "; for(int o=0;o<=Grado;o++){cout<<" x^"<<o<<"= "<<coeficientes[o];}
    cout<<endl<<endl;

    complex<double> raices[Grado]; // vector tipo complejo donde se guardarán los resultados finales de las raices

    int Operador_Grado = 1;

    int r = 0, s = 0, iter=0;
    r = ((double) rand() / RAND_MAX) * 2 - 1; // se escoge un valor aleatorio entre 1 y -1 para r y s
    s = ((double) rand() / RAND_MAX) * 2 - 1;

    double b[Grado+1];
    double a[Grado+1];
    double c[Grado+1];
    b[0] = 1;
    c[0] = -1; // en referencia a las formulas se inicializan b0 en 1 c0 en -1 y a0 como el primer coeficiente
    a[0] = coeficientes[0];

    while(abs(dr/r) > Tolerancia || abs(ds/s) > Tolerancia){ // tolerancia para limitar los ciclos antes de encontrar raices
        Operador_Grado = 1;
        while(Operador_Grado <= Grado){

            a[Operador_Grado] = coeficientes[Operador_Grado];

            if(Operador_Grado < 2){

                b[Operador_Grado] = a[Operador_Grado] - b[Operador_Grado-1]*r; // se obtienen los valores del arreglo b y c para aplicar la fórmula
                c[Operador_Grado] = -b[Operador_Grado] - r*c[Operador_Grado-1];

            }
            else{

                b[Operador_Grado] = a[Operador_Grado] - b[Operador_Grado-1]*r - b[Operador_Grado-2]*s;
                c[Operador_Grado] = -b[Operador_Grado] - r*c[Operador_Grado-1] - s*c[Operador_Grado-2];

            }
            Operador_Grado++;

        }
        dr= ((b[1]*c[4])-(b[2]*c[3]))/((c[2]*c[4])-(c[3]*c[3])); //formulas aplicadas
        ds= ((b[2]*c[2])-(b[1]*c[3]))/((c[2]*c[4])-(c[3]*c[3]));

        double delta = ((coeficientes[Grado-1]*coeficientes[Grado-1]) - 4*coeficientes[Grado]*coeficientes[Grado-2]); //obtención de delta para verificar raices complejas

        if(delta>=0){

            raices[iter] = (-r + sqrt(delta))/2.0; //formula para obtener las raices con delta
            raices[iter+1] = (-r - sqrt(delta))/2.0;

            cout<<"raiz x^"<<iter<<"= "<<raices[iter]<<endl; // salida de datos por pantalla para mostrar las raices
            cout<<"raiz x^"<<iter+1<<"= "<<raices[iter+1]<<endl;

            iter+=2;

        }else{

            raices[iter] = (-r + sqrt(delta))/2.0; //formula para obtener las raices con delta
            raices[iter+1] = (-r - sqrt(delta))/2.0;

            cout<<"raiz x^"<<iter<<"= "<<raices[iter]<<endl; // salida de datos por pantalla para mostrar las raices
            cout<<"raiz x^"<<iter+1<<"= "<<raices[iter+1]<<endl;
        }

        r=r+dr;
        s=s+ds;
    }
	
}
