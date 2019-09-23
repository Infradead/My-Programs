//available at http://www.algolist.com/code/java/Dijkstra%27s_algorithm
//implements Dijkstra's Shortest Path Algorithm
// *** This is not my code. I needed this code so that my other code would run. ***
 
import java.util.PriorityQueue;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

///////////////
//Vertex class 
///////////////
class Vertex implements Comparable<Vertex>
{
    public final String name;
    public Edge[] adjacencies;
    public double minDistance = Double.POSITIVE_INFINITY;
    public Vertex previous;
    
    public Vertex(String argName) 
    { 
      name = argName; 
    }
    public String getSourceName()
    {
      return name;
    }
    public int compareTo(Vertex other)
    {
        return Double.compare(minDistance, other.minDistance);
    }
}

///////////////
//Edge class 
///////////////
class Edge
{
    public final Vertex target;
    public final double weight;
    public Edge(Vertex argTarget, double argWeight)
    { 
      target = argTarget; 
      weight = argWeight; 
    }
    public double getWeight() // new addition
    {
      return weight;
    }
    public Vertex getTarget()
    {
      return target;
    }
}


////////////////////////////////////
// Dijkstra's Shortest path class 
///////////////////////////////////
public class Dijkstra
{
    public static void computePaths(Vertex source)
    {
        source.minDistance = 0.;
        PriorityQueue<Vertex> vertexQueue = new PriorityQueue<Vertex>();
      	vertexQueue.add(source);

	     while (!vertexQueue.isEmpty()) 
        {
	        Vertex u = vertexQueue.poll();

            // Visit each edge exiting u
            for (Edge e : u.adjacencies)
            {
                Vertex v = e.target;
                double weight = e.weight;
                double distanceThroughU = u.minDistance + weight;
                
		          if (distanceThroughU < v.minDistance) 
                {
		               vertexQueue.remove(v);
		               v.minDistance = distanceThroughU;
		               v.previous = u;
		               vertexQueue.add(v);
		          }
            }
        }
    }

    public static List<Vertex> getShortestPathTo(Vertex target)
    {
        List<Vertex> path = new ArrayList<Vertex>();
        for (Vertex vertex = target; vertex != null; vertex = vertex.previous)
            path.add(vertex);
        Collections.reverse(path);
        return path;
    }

 }//end Dijkstra class 
