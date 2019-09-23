public class Notecard
{
   private String mDefinition;
   private String mTerm;
   private boolean mMemorized;
   
   public Notecard(String d, String t)
   {
      mDefinition = d;
      mTerm = t;
   } 
   public void memorized()
   {
      mMemorized = true;
   }
   public void setTerm(String t)
   {
      mTerm = t;
   }
   public void setDefinition(String d)
   {
      mDefinition = d;
   }
   public String getTerm()
   {
      return mTerm;
   }
   public String getDefinition()
   {
      return mDefinition;
   }
   public String toString()
   {
      return "Card term: "+getTerm()+" Card definition: "+getDefinition();
   }
}