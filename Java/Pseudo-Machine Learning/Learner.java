import java.util.*;

public class Learner
{
   private int x;
   private final int min = 1; // start value
   private int max; // end node value
   private ArrayList<Route> routes = new ArrayList<Route>(); // holds routes for comparision
   public ArrayList<Integer> directions = new ArrayList<Integer>();
   Scanner input = new Scanner(System.in);
  
   public void createRoute()
   {
      System.out.println("Where would you like your Uber driver to take you? \n"+
                           "Here are your options: 2, 4, 6, 8, 10, 12, 14, 16"); 
      max = input.nextInt();
      if(max % 2 == 0 && max <= 16 && max > min)
      {
         for(int i = 0; i < max; i++)
         {
            if(directions == null && routes == null)
               directions.add((int)Math.random() * max);
            if(directions.get(i) == max)
            {
               routes.add(new Route(directions, max));        
               directions.clear();
               break;
            }                
         }     
      }
      else
      createRoute();
      
      showRoutes();
               
   } 
  public Route compareRoutes(int endNode)
  {
     ArrayList<Route> matchedRoutes = new ArrayList<Route>();
     for(int i = 0; i < routes.size(); i++)
     {
        if(routes.get(i).getEnd() == endNode)
        {
           matchedRoutes.add(routes.get(i));
        }
     }
     for(int f = 0; f < matchedRoutes.size(); f++)
     {
        for(int g = 0; f < matchedRoutes.get(f).size(); g++)
        {
            if(matchedRoutes.get(f).getPath(g).size()-1 = g)
            {
               if(matchedRoutes.get(f).getPath(g).size() < matchedRoutes.get(f).getPath(g+1).size())
               {
                  matchedRoutes.get(f).get(f).remove(g+1);
               }
            }
            else if(matchedRoutes.get(f).getPath(g).size() < matchedRoutes.get(f).getPath(g+1).size())
            matchedRoutes.get(f).remove(g+1); 
        }
      }
  } 
   public void showRoutes()
   {
      for(int i = 0; i < routes.size(); i++)
         for(int f = 0; f < routes.get(i).size(); f++)   
         System.out.println("Route"+i+": "+routes.get(i).getPath(f));
   }
   public void showRoutes(int n)
   {
      for(int f = 0; f < routes.get(n).size(); f++)
      System.out.println(routes.get(n).getPath(f));
   }
  
}

class Route
{
   public int mEnd;
   public ArrayList<Integer> directions;
   
   public Route(ArrayList<Integer> dir, int end)
   {
      mEnd = end;
      directions = dir;  
   }
   public int getEnd()
   {
      return mEnd;
   }
   public int getPath(int i)
   {
      return directions.get(i); 
   }
   public void getNodes()
   {
      for(int i = 0; i < directions.size(); i++)
      directions.get(i);
   }
   public int size()
   {
      return directions.size();
   }
   public int getDirection(int i)
   {
      return directions.get(i);
   }
   

}   
