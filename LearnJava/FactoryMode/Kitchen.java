public class Kitchen
{
	public ChooseWay choose(String s)
	{
		if(s == "waiter")
		{
			ChooseWay w = new CalWater();
			return w;
		}
		if(s == "computer")
		{
			ChooseWay w = new UseComputer();
			return w;
		}
		System.out.println("������ѡ��");
		return null;
	}
	
}