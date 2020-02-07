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
initialization_file=system("grep 'initialization_file' $1 | awk '{print $3}'")
randomness=system("grep 'randomness' $1 | awk '{print $3}' >> variables")
kick=system("grep 'kick_type' $1 | awk '{print $3}' >> variables")
file_name=system("grep 'file_name' $1 | awk '{print $3}' >> variables")
step_width=system("grep 'step_width' $1 | awk '{print $3}' >> variables")
Temperature=system("grep 'temperature_K' $1 | awk '{ print $3 }' >> variables")
Ncore=ncore=system("grep '#BSUB -n' $0 | head -1 | awk '{print $3}' >> variables")
iteraciones=system("grep 'iterations' $1 | awk '{ print $3 }' >> variables")
path=system("grep 'initialization_file' $1 | awk '{ print $3 }' >> variables")
Npath=system("echo $path | wc -c >> variables")
m=1 //contador de coords rechazadas
swap_step=system("grep 'swap_step' $1 | awk '{ print $3 }' >> variables")


//################################# CREATES Work Directory #####################################
command="if [ -d $file_name ] ; then mv $file_name other_$file_name ; fi ; cp -r input $file_name";
system(comand);

//##############################################################################################
//#                                         BEGIN ALGORITHM                                    #
//##############################################################################################

system("cd $file_name ; mkdir rejected");
contenido=0;
count=1;
while(contenido!=1)
{

  if(initialization_file!=false && count==1)
  {
    //Inicializa archivo geometry.in
    system("cp initalization_file geometry.in")
    count++;
  }
  else
  {
    //Empieza desde 0
    if(type == "bimetalic")  //Esto quiere decir que es bimetalico
    {
      if(randomness==1)  // fully random
      {
        clus.srand_generator
      }
      else //pseudoaleatorio
      {
        clus.rand_generator
      }
    }
    else //es monometalico
    {
    	if(randomness==1)  // fully random
      {
        clus.srand_generator
      }
      else //pseudoaleatorio
      {
        clus.rand_generator
      }
    }
  }
    
  system("./run.sh");
  system("grep 'Have a nice day.' output.out | wc -l > contenido.txt"); //Checar output nombre, poner if=1 then
  ifstream cont("contenido.txt");
  cont>>contenido;
  cont.close();
  system("rm contenido.txt");

}

system("grep \" | Total energy of the DFT / Hartree-Fock s.c.f. calculation \" output.out | cut -d \":\" -f 2 > energy.txt")
ifstream en("energy.txt");
en>>energy;
en.close();
system("rm energy.txt");

clus.read_fhi("geometry.in.next_step");
clus.print_xyz("coordinates1.xyz");
system("mv output.out output1.out");
system("mv geometry.in geometry1.in");
system("echo Step Energy >> energies.txt");
system("echo 1     "+to_string(energy)+" >> energies.txt".c_str() );

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
    clus.swap(swap_step);
  }
  else
  {
    //aplica move;
    if(kick==0)
    {
      clus.kick(step_width);
    }
    else
    {
      clus.kicklenard(step_width);
    }
  }
  system("./run.sh");
  system("grep 'Have a nice day. ' output.out | wc -l > contenido.txt");
  ifstream cont("contenido.txt");
  cont>>contenido;
  cont.close();
  system("rm contenido.txt");
  

  while (contenido!=1)
  {
  cout<<" --> SCF failed. Starting again from randomly generated structure! "<<endl;

  if(n>3)  //Esto quiere decir que es bimetalico
  {
    	if(randomness==1)  // fully random
      {
        clus.srand_generator
      }
      else //pseudoaleatorio
      {
        clus.rand_generator
      }
  }
  else //es monometalico
  {
      	if(randomness==1)  // fully random
      {
        clus.srand_generator
      }
      else //pseudoaleatorio
      {
        clus.rand_generator
      }
  }

  system("./run.sh");
  system("grep 'Have a nice day. ' output.out | wc -l > contenido.txt");
  ifstream cont("contenido.txt");
  cont>>contenido;
  cont.close();
  system("rm contenido.txt");
  }

  ################################################################################################
  #                                     Save  configuration                                      #
  ################################################################################################


EnergiaAnterior=energy;
system("grep \" | Total energy of the DFT / Hartree-Fock s.c.f. calculation \" output.out | cut -d \":\" -f 2  | cut -d 'e' -f 1 > energy.txt");
ifstream en("energy.txt");
en>>energy;
en.close();
system("rm energy.txt");

clus.read_fhi("geometry.in.next_step");
clus.print_xyz("cordinates"+to_string(i)+".xyz".c_str(), energy );
system("mv output.out output"+to_string(i)+".out".c_str());
system("mv geometry.in geometry"+to_string(i)+".in".c_str());
system("echo "+to_string(i)+"  "+to_string(energy)+" >> energies.txt".c_str() );


  ################################################################################################
  #                                  Metropolis Monte-Carlo                                      #
  ################################################################################################


kBT = 0.00008617 * temperature_K;
if (pow(e,(EnergiaAnterior-energy)/kBT) > random_number(0,1))
{
	cout<<"--> Basin Hopping MC criteria: Energy accepted! "<<endl;
    cout<<"--> Finished iteration $i"<<endl;
    system("tail "-$i "energies.txt |  sort -nk2 > sorted.txt");
    i++;
}
else
{
	cout<<echo "--> Basin Hopping MC criteria: Energy rejected!"<<endl;
    system("mv output"$i".out rejected/outputrejected"$i".out");
    system("mv geometry"$i".in rejected/geometryrejected"$i".in");
    m++;
}
}
return 0;
}
