// BasePlusCommissionEmployee class represents an employee who receives a base salary in addition to commission
public class BasePlusCommissionEmployee
{
   private CommissionEmployee commissionEmployee; // composition
   private double baseSalary; // base salary per week

   // six-argument constructor
   public BasePlusCommissionEmployee( String first, String last, String ssn, double sales, double rate, double salary )
   {
      commissionEmployee = new CommissionEmployee( first, last, ssn, sales, rate );
      setBaseSalary( salary ); // validate and store base salary
   } // end six-argument BasePlusCommissionEmployee constructor
   
   // set first name
   public void setFirstName( String first )
   {
      commissionEmployee.setFirstName( first );
   } 

   // return first name
   public String getFirstName()
   {
      return commissionEmployee.getFirstName();
   } 

   // set last name
   public void setLastName( String last )
   {
      commissionEmployee.setLastName( last );
   } 

   // return last name
   public String getLastName()
   {
      return commissionEmployee.getLastName();
   } 

   // set social security number
   public void setSocialSecurityNumber( String ssn )
   {
      commissionEmployee.setSocialSecurityNumber( ssn );
   } 

   // return social security number
   public String getSocialSecurityNumber()
   {
      return commissionEmployee.getSocialSecurityNumber();
   } 

   // set commission employee's gross sales amount
   public void setGrossSales( double sales )
   {
      commissionEmployee.setGrossSales( sales );
   } 

   // return commission employee's gross sales amount
   public double getGrossSales()
   {
      return commissionEmployee.getGrossSales();
   } 
   
   // set commission employee's rate
   public void setCommissionRate( double rate )
   {
      commissionEmployee.setCommissionRate( rate );
   } 

   // return commission employee's rate
   public double getCommissionRate()
   {
      return commissionEmployee.getCommissionRate();
   } 

   // set base-salaried commission employee's base salary
   public void setBaseSalary( double salary )
   {
      baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
   } 

   // return base-salaried commission employee's base salary
   public double getBaseSalary()
   {
      return baseSalary;
   } 

   // calculate base-salaried commission employee's earnings
   public double earnings()
   {
      return getBaseSalary() + commissionEmployee.earnings();
   } 

   // return String representation of BasePlusCommissionEmployee
   @Override
   public String toString()
   {
      return String.format( "%s %s\n%s: %.2f", "base-salaried", commissionEmployee.toString(), "base salary", getBaseSalary() );
   } 
} // end class BasePlusCommissionEmployee
