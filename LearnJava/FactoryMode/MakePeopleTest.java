public class MakePeopleTest
{
	public static void main(String[] args)
	{
		PeopleFactory p = new PeopleFactory();
		People p1 = p.makePeople("ÄÐ");
		p1.makePeople();
		People p2 = p.makePeople("Å®");
		p2.makePeople();
	} 
}