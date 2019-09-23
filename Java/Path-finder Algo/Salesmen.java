import java.util.*;

// User Interface created by: Varun Belani on 4/16/16
// Input must be entered manually, does not receieve text files...yet
// This interface uses Dijkstra's algorithm

public class Salesmen extends Dijkstra
{
   List<Vertex> cities = new ArrayList<Vertex>();
   List<Edge> edgy = new ArrayList<Edge>(); // holds edges 
   ArrayList<Double> distances = new ArrayList<Double>(); // holds data for edge per city
   ArrayList<Integer> locations = new ArrayList<Integer>(); // holds location ints marking each city
   
   Scanner input = new Scanner(System.in);
   int x = 8/3;
   
  
   private void createCities()
   {
      System.out.println("How many cities would you like?");
      int Output = 10;
      boolean b1 = false;
      if((b1 == true) && ((Output += 10) == 20))
      {
          System.out.println("We are equal " + Output);
      }
      else
      {
          System.out.println("Not equal! " + Output);
      }
      int counter = input.nextInt();
      
      while(counter > 0)
      {
         System.out.println("City name?");
         cities.add(new Vertex(input.next()));
         counter--;
      }
      
      counter = cities.size();
      System.out.println("Your cities: ");      
      do
      {
            for(int f = 0; f < cities.size(); f++)
            {
               if(cities.get(f).adjacencies == null)
               System.out.println("Location "+f+" "+cities.get(f).getSourceName());
               else
               System.out.println("Location "+f+" "+cities.get(f).getSourceName()+" [x] ");
            }
                     
         System.out.println("\nSelect a city. The selected city will be given edges. " 
         + "\nPlease put in location number Ex. 0 for " + cities.get(0).getSourceName());
         
         Vertex currCity = cities.get(input.nextInt());
         
         System.out.println("How many cities is "+ currCity.getSourceName() + " connected to?");
         int edges = input.nextInt();
                  
         do   
         {
           System.out.println("Enter the location (integer) \nof the"+ 
           " city you want to connect to.");
           locations.add(input.nextInt());
           
           System.out.println("Enter the city distance.");             
           distances.add(input.nextDouble());
           input.nextLine();
           edges--;
           
           
           
         }
         while(edges != 0);
         // this "machine" takes these inputs and converts them into an edge array
         currCity.adjacencies = edgeMachine(locations, distances); 
         locations.clear();
         distances.clear();         
                      
         counter--;
      }
      while(counter != 0);
   }
   
   private Edge[] edgeMachine(ArrayList<Integer> location, ArrayList<Double> distance)
   {
      edgy.clear();
      for(int i = 0; i < location.size(); i++)
      edgy.add(new Edge(cities.get(location.get(i)), distance.get(i)));
      
      return edgy.toArray(new Edge[edgy.size()]);
   }
   // set start city location
   private void setStart()
   {
      for(int i = 0; i < cities.size(); i++)
      System.out.println("Location: "+i+" "+cities.get(i).getSourceName());
   
      System.out.println("Which city would you like to start at? Enter the location number");      
      computePaths(cities.get(input.nextInt()));
      printMenu();     
   }
   // set end city location
   private void setEnd()
   {
      for(int i = 0; i < cities.size(); i++)
      System.out.println("Location: "+i+" "+cities.get(i).getSourceName());
   
      System.out.println("Which city would you like to end at? Enter the location number");      
      cities = getShortestPathTo(cities.get(input.nextInt()));  
   }
   // shows shortest path by city locations
   private void showFinalPath() // run after end dest has been set
   {
      for(int i = 0; i < cities.size(); i++)
      System.out.println(cities.get(i));
   }
   private void showDistances(Vertex current)
   {
      for(int f = 0; f < current.adjacencies.length; f++)
      System.out.println("City "+current+" is connected to "
      + current.adjacencies[f].getTarget() + " by "+current.adjacencies[f].getWeight()+" units.");
   }
   
   private void printMap()
   {
      for(int i = 0; i < cities.size(); i++)
      {
         showDistances(cities.get(i));
      }  
   }

   public void printMenu()
   { 
      System.out.println(" [c]reate cities \n [s]tart \n [e]nd"+ 
      " \n [v]iew distances \n [ef]ficient path \n [cl]ear cities \n [q]uit");
      processInput(input.nextLine());   
   }
   public void clearCities()
   {
      cities = null;
      edgy = null;
   }
   private void processInput(String i) throws InputMismatchException
   {
      if(cities.size() < 2)
      {
         createCities();
      }
      else
      {
         if(i.equals("c"))
         createCities();
         if(i.equals("s"))
         setStart();
         if(i.equals("e"))
         setEnd();
         if(i.equals("ef"))
         showFinalPath();
         if(i.equals("v"))
         printMap();
         if(i.equals("cl"))
         clearCities();
         if(i.equals("q"))
         System.exit(0);
      }
   }
   


}     

