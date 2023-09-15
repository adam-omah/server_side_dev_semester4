# server_side_dev_semester4
Server Side Project For semester 4 of college
Server Side Development 

Property Rental System 


Database Name: property rental  

SQL File Name: propertyrental.sql in the folder named FinalDBWithData. 

 

 

The system for my project is based on a property rental system, it does not cover the entirety of the rental process, but it does cover adding owners of properties to a database, properties associated with those owners and then allows the rental of these properties to tenants on given dates as long as it does not conflict with any already existing rental for that property. 

Owners can be updated, removed and added, however if a owner is added and is the owner of a property this owner cannot be removed. 

Properties can be added and rented, the rental is a process involving searching a desired town and supplying the dates you want, if there is a property available in the town you searched it will return all the available properties for those dates. 

For each element there are multiple examples so I will try to keep it brief on where to find them. 

Insertion: Add Owner, the code is found in the includes folder in the sub-section Code in a file called addOwnerCode.inc. 


Delete: Remove Owner, the code is found in the includes folder in the sub-section Code in a file called removeOwnerCode.inc. 

Select: found in the Rent Property function, the code for the selection is found in the includes folder in the sub-section Code in a file called propertiesFoundCode.inc. 

Update: Update Owner, the code is found in the includes folder in the sub-section Code in a file called updateOwnerCode.inc. 

Process: Rent Property, involves several actions found in the code sub folder rentPropertyCode.inc, the propertiesFoundCode.inc, and the forms sub folder findProperties.inc, selectPropertyToRent.inc. 

A relation scheme of the database:

Database Schema: PropertySYS

 

Relation Owners  

Owner_ID smallint (5) Unsigned Auto Incremented. 

firstName char (30) NOT NULL 

lastName char (40) NOT NULL 

phone Varchar (15) NOT NULL 

email Varchar (50) NOT NULL 

eircode char (7) NOT NULL 

status char (1) not null default ‘A’ 

Primary Key: 	Owner_ID 

 

Relation Properties 

Eircode Varchar (7)  

Town Varchar (50) NOT NULL, 

Address Varchar (100) NOT NULL, 

description Varchar (200) NOT NULL 

monthlyRent Numeric (10,2) NOT NULL check > 0 

bedrooms tinyInt (2) check >= 0 

bathrooms tinyInt (2) check >= 0 

parkingSpaces tinyInt (2) check >= 0 

gardenSpace Char (1) DEFAULT ‘N’ 

petsAllowed Char (1) DEFAULT ‘N’ 

ownerOccupied Char (1) DEFAULT ‘N’ 

status Char (1) DEFAULT ‘A’ CHECK ‘A’ OR ‘U’ OR ‘R’ 

Owner_ID smallint (5) NOT NULL 

type varchar (30) NOT NULL 

Primary Key:	Eircode 

Foreign Key:	Owner_ID References Owners. 


Relation Tenants 

Tenant_ID smallint (5) Unsigned Auto Incremented. 

firstName char (30) NOT NULL 

lastName char (40) NOT NULL 

phone Varchar (15) NOT NULL 

email Varchar (50) NOT NULL 

Status char DEFAULT ‘A’ CHECK ‘A’ OR ‘I’ 

Primary Key: 	Tenant_ID 

 

Relation Rentals 

Rental_ID smallint (7) Unsigned Auto Incremented. 

startDate Date NOT NULL  

endDate Date NOT NULL 

rentCost decimal (10,2) NOT NULL 

Status Char (1) DEFAULT ‘A’ CHECK ‘A’ OR ‘I’  

Eircode Varchar (7) NOT NULL 

Tenant_ID Numeric (5) NOT NULL, 

Primary Key: 	Rental_ID 

Foreign Key:	Eircode References Properties, 

Tenant_ID References Tenants. 
