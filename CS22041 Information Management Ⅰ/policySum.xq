let $test := doc('insurancePolicy.xml')/policyList/insurancePolicy
  return ("Sum of policy figures: ", sum($test/amount), "Individual policy figures: ", $test/amount)