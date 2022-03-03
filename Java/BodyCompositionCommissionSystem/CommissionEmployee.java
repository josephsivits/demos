// CommissionEmployee class represents an employee paid a percentage of gross sales
public class CommissionEmployee extends Object {
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;
    private double grossSales;      // gross weekly sales
    private double commissionRate;  // commission percentage

    // five arguemnt constructor
    public CommissionEmployee(String firstName, String lastName, String socialSecurityNumber, double grossSales, double commissionRate)
    {
        // imlicit call to Object's default constructor occures here

        // if grossSales is invalid throw exception
        if(grossSales < 0.0)
        {
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        }

        // if commissionRate is invalid throw exception
        if(commissionRate <= 0.0 || commissionRate >= 1.0)
        {
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
        }

        this.firstName = firstName;
        this.lastName = lastName;
        this.socialSecurityNumber = socialSecurityNumber;
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
    } // end 5 argument constructor

    // get functions
    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getSocialSecurityNumber() { return socialSecurityNumber; }

    // set gross sales
    public void setGrossSales(double grossSales)
    {
        if(grossSales < 0.0)
        {
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        }
        this.grossSales = grossSales;
    }

    // return gross sales amount
    public double getGrossSales() { return grossSales; }

    // set commission rate
    public void setCommissionRate(double commissionRate)
    {
        if(commissionRate <= 0.0 || commissionRate >= 1.0)
        {
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
        }
        this.commissionRate = commissionRate;
    }

    public void setFirstName(String fName) { this.firstName = fName; }
    public void setLastName(String lName) { this.firstName = lName; }
    public void setSocialSecurityNumber(String ssn) { this.socialSecurityNumber = ssn; }

    // return commission rate
    public double getCommissionRate() { return commissionRate; }

    // calculate earnings
    public double earnings() { return commissionRate * grossSales; }

    // return String representation of CommissionEmployee object
    @Override
    public String toString()
    {
        return String.format("%s: %s %s%n%s: %s%n%s: %.2f%n%s: %.2f",
        "commission employee   ", getFirstName(), getLastName(),
        "social security number",getSocialSecurityNumber(),
        "gross sales           ", getGrossSales(),
        "commission rate       ", getCommissionRate());
    }
}