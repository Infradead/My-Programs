import java.util.ArrayList;

public class Stack extends ArrayList<Notecard>
{   
   private String mStackName;
   
   ArrayList<Stack> StackArray = new ArrayList<Stack>();
   
   public Stack(String name)
   {
      mStackName = name;
   }
   public void setStackName(String s)
   {
      mStackName = s;
   }
   public String getStackName()
   {
      return mStackName;
   }
   public int getNumberCards()
   {
      return size();
   }
   public void addCard(Notecard c)
   {
      add(c);
   }
   public void deleteCard(int element)
   {
      StackArray.remove(element);
   }
   // public static void deleteCard(int element String StackName)
//    {
//       for(int i = 0; i < StackArray.size(); i++)
//       if(StackArray.getStackName().equals(StackName))remove(element);
   public void createStack(String n)
   {
//       Stack stack = new Stack(n);
      StackArray.add(new Stack(n));
//       mNumberStacks++;
   }
   public void deleteStack(int e)
   {
      StackArray.remove(e);
   }
   public Stack getStack(int e)
   {
      return StackArray.get(e);
   }
   public Notecard getNotecard(int e)
   {
      return get(e);
   }
      
   
}
   