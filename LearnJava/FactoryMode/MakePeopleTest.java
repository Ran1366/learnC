public class MakePeopleTest
{
	public static void main(String[] args)
	{
		PeopleFactory p = new PeopleFactory();
		People p1 = p.makePeople("��");
		p1.makePeople();
		People p2 = p.makePeople("Ů");
		p2.makePeople();
	} 
}