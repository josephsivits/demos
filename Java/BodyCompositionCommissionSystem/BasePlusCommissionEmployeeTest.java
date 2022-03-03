// Using composition instead of inheritance
public class BasePlusCommissionEmployeeTest
{
    public static void main(String[] args)
    {
        BasePlusCommissionEmployee emp = new BasePlusCommissionEmployee("Joseph", "Sivits", "222-33-4444", 10000, .08, 500);

        System.out.println("Employee information obtained by get methods:");
        System.out.printf("%s %s%n", "First name is",emp.getFirstName());
        System.out.printf("%s %s%n", "Last name is",emp.getLastName());
        System.out.printf("%s %s%n", "SSN is",emp.getSocialSecurityNumber());
        System.out.printf("%s %.2f%n", "Gross sales is",emp.getGrossSales());
        System.out.printf("%s %.2f%n", "Commission rate is",emp.getCommissionRate());
        System.out.printf("%s %.2f%n", "Base salary is",emp.getBaseSalary());

        emp.setGrossSales(5000);
        emp.setCommissionRate(.1);
        emp.setBaseSalary(1000);

        System.out.printf("%n%s:%n%n%s%n", 
        "Updated employee information obtained by overriden toString",
        emp);
    }
}
