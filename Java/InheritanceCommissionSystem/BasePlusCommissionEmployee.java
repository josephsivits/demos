// BasePlusCOmmissionEmployee class inherits from CommissionEmployee and accesses the superclass's private data via inherited
public class BasePlusCommissionEmployee extends CommmissionEmployee {
    private double baseSalary;

    public BasePlusCommissionEmployee(String firstName, String lastName, String socialSecurityNumber, double grossSales, double commissionRate, double baseSalary)
    {
        super(firstName, lastName, socialSecurityNumber, grossSales, commissionRate);
        if(baseSalary < 0.0)
        {
        throw new IllegalArgumentException("Base salary must be >= 0.0");
        }
        this.baseSalary = baseSalary;
    }

    // if baseSalary is invalid throw exception


    public void setBaseSalary(double baseSalary)
    {
        if(baseSalary < 0.0)
        {
            throw new IllegalArgumentException("Base salary must be >= 0.0");
        }
        this.baseSalary = baseSalary;
    }

    public double getBaseSalary() { return baseSalary; }

    // calculate earnings
    @Override
    public double earnings() { return getBaseSalary() + super.earnings(); }

    @Override
    public String toString()
    {
        return String.format("%s %s%n%s: %.2f", "base-salaried", super.toString(), "base salary",getBaseSalary());
    }
}
