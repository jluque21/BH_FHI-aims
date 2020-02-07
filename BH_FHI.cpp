#include<atomicpp.h>

int continue_alg, randomness, kick, iteraciones,swap_step, contenido;
float step_width, temperature ;
string file_name, command;
int main(int argc, char *argv[]){

//################################################################################################
//#                                    Gets data from input.bh                                   #
//################################################################################################

Simbolo_1=system("grep 'cluster_ntyp' $1 | cut -d '[' -f 2 | cut -d ':' -f 1 >> variables")
Simbolo_2=system("grep 'cluster_ntyp' $1 | cut -d '[' -f 3 | cut -d ':' -f 1) 2>/dev/null >> variables")
N_Simbolo_1=system("grep 'cluster_ntyp' $1 | cut -d '[' -f 2 | cut -d ':' -f 2 | cut -d ']' -f 1 >> variables")
N_Simbolo_2=0
N_Simbolo_2=system("grep 'cluster_ntyp' $1 | cut -d '[' -f 3 | cut -d ':' -f 2 | cut -d ']' -f 1) 2>/dev/null >> variables")
n=system("grep 'cluster_ntyp'  $1 | awk '{print $4}' | wc -c >> variables")  //Este es un criterio para determinar si es bimetÃ¡lico o no

continue=system("grep 'continue' $1 | cut -d ' ' -f 3 >> variables")

randomness=system("grep 'randomness' $1 | awk '{print $3}' >> variables")
kick=system("grep 'kick_type' $1 | awk '{print $3}' >> variables")
file_name=system("grep 'file_name' $1 | awk '{print $3}' >> variables")
step_width=system("grep 'step_width' $1 | awk '{print $3}' >> variables")
Temperature=system("grep 'temperature_K' $1 | awk '{ print $3 }' >> variables")
//if [ $n -gt 3 ]
//then
//Nat=N_Simbolo_1+N_Simbolo_2 //Numero de atomos del cluster
//else
//Nat=N_Simbolo_1
//fi
Ncore=ncore=system("grep '#BSUB -n' $0 | head -1 | awk '{print $3}' >> variables")
iteraciones=system("grep 'iterations' $1 | awk '{ print $3 }' >> variables")
path=system("grep 'initialization_file' $1 | awk '{ print $3 }' >> variables")
Npath=system("echo $path | wc -c >> variables")
m=1 //contador de coords rechazadas
swap_step=system("grep 'swap_step' $1 | awk '{ print $3 }' >> variables")


if(argc == 17 )
{
   Simbolo_2=argv[14];
   N_Simbolo_2=stoi(argv[15]);
}

//################################# CREATES Work Directory #####################################
command="if [ -d $file_name ] ; then mv $file_name other_$file_name ; fi ; cp -r input $file_name";


//##############################################################################################
//#                                         BEGIN ALGORITHM                                    #
//##############################################################################################


system("mkdir rejected");
contenido=0;
count=1;
while(contenido!=1)
{

  if(initialization_file==1 && count==1)
  {
    //Inicializa archivo geometry.in
    count++;
  }
  else
  {
    //Empieza desde 0
    if(n>3)  //Esto quiere decir que es bimetalico
    {
      if(randomness==1)  // fully random
      {
        // clus.SRandomGenerator(...)
      }
      else //pseudoaleatorio
      {
        // clus.RandomGenerator(...)
      }
    }
    else //es monometalico
    {
        if(randomness==1)  // fully random
        {
          // clus.SRandomGenerator(...)
        }
        else //pseudoaleatorio
        {
          // clus.RandomGenerator(...)
        }
    }
  }
    
  system("./run.sh");
  system("grep 'Have a nice day.' output.out | wc -l > contenido.txt"); //Checar output nombre, poner if=1 then
  ifstream cont...
  //read contenido.txt
}

/////////  MODIFICAR ESTO PARA FHI AIMS (AHORITA ESTA PARA vasp)
system("grep \" | Total energy of the DFT / Hartree-Fock s.c.f. calculation \" output.out | cut -d \":\" -f 2 >> energy.txt")
readfhi(geometry.in.next_step) print_xyz (geometry1.xyz)   // Dentro de loop
mv output.out output1.out   // Dentro de loop


//cout<<"Step  Energy" >> energies.txt;
//cout<<echo "1     $Energia" >> energies.txt

cout<<" --> Relaxation of initial configuration: DONE! "<<endl<<endl;
cout<<"=================================================================="<<endl;
cout<<"BH-DFT routine starts here! "<<endl;
cout<<"Note: "<<endl;
cout<<"For monometallic clusters: only random xyz moves will be applied "<<endl;
cout<<"For bimetallic clusters  : 1 atomic swap will be performed after 10 moves "<<endl;
cout<<"==================================================================="<<endl<<endl;

i=2

while(i+m < iteraciones)
{
  resto=i%swap_step;
  //extract cluster
  if(n>3) //es bimetalico
  {
    cluster=extract(Simbolo_1,outputfile);
    cluster=extract(Simbolo_2,outputfile);
    cluster=cluster+cluster;
  }
  else //es monometalico
  {
    cluster=extract(Simbolo_1,outputfile);
  }
  if(resto==0)
  {
    //aplica swap;
  }
  else
  {
    //aplica move;
    if(kick==0)
    {
      //aplica tipo depatada =0
    }
    else
    {
      //aplica la otra patada
    }
  }
  system("./run.sh");
  system("grep 'Have a nice day. ' output.out | wc -l > contenido.txt");
  ifstream cont...
  //read contenidoi=contenido.txt

  while (contenido!=1)
  {
  cout<<" --> SCF failed. Starting again from randomly generated structure! "<<endl;

  if(n>3)  //Esto quiere decir que es bimetalico
  {
    if(randomness==1)  // fully random
    {
      // clus.SRandomGenerator(...)
    }
    else //pseudoaleatorio
    {
      // clus.RandomGenerator(...)
    }
  }
  else //es monometalico
  {
      if(randomness==1)  // fully random
      {
        // clus.SRandomGenerator(...)
      }
      else //pseudoaleatorio
      {
        // clus.RandomGenerator(...)
      }
  }

  system("./run.sh");
  system("grep 'Have a nice day. ' output.out | wc -l > contenido.txt");
  ifstream cont...
  //read contenidoi=contenido.txt
  }

  ################################################################################################
  #                                     Save  configuration                                      #
  ################################################################################################

     EnergiaAnterior=$(echo $Energia)
    // Energia=$(tail -1 OSZICAR | awk '{print $5 }')    #Extrae energia del OSZICAR

     echo "$i     $Energia " >> CONTCAR$i
     N=$(wc -l CONTCAR | awk '{ print $1 }' )
     tail -$(($N-1)) CONTCAR >> CONTCAR$i  //Renombra los archivos y les agrega la energia
     mv POSCAR POSCAR$i
     //rm CHG CHGCAR DOSCAR OSZICAR EIGENVAL XDATCAR IBZKPT  PCDAT REPORT WAVECAR *.xml CONTCAR

  ################################################################################################
  #                                  Metropolis Monte-Carlo                                      #
  ################################################################################################

     accepted=$(python ../programs/metropolis.py $EnergiaAnterior $Energia $Temperature)

        if [ $accepted = true ]
        then   // La energia ha sido aceptada

          echo "--> Basin Hopping MC criteria: Energy accepted! "
          echo "--> Finished iteration $i"
          head -1 CONTCAR$i >> energies.txt
          tail -$i energies.txt |  sort -nk2 > sorted.txt
          i=$(($i+1)) //Convergencia lograda, aumenta en 1 el contador

        else

          echo "--> Basin Hopping MC criteria: Energy rejected!"
          mv output$i.outt rejected/outputrejected$i.out
          mv geometry$i.in rejected/geometryrejected$i.in
          m=$(($m+1))

        fi
}
return 0;
}
