-- Keep a log of any SQL queries you execute as you solve the mystery.
-- airports
-- atm_transactions
-- bakery_security_logs
-- bank_accounts
-- crime_scene_reports
-- flights
-- interviews
-- passengers
-- people
-- phone_calls

SELECT * FROM crime_scene_records WHERE day = 28 AND month = 7;
-- 10.15 am at the Humphrey street bakery. 3 witnesses who were present at the time. Bakery mentions

SELECT * FROM interviews WHERE day = 28 AND month = 7;
-- Ruth, Eugene, Raymond
-- bakery parking lot cars left the parking lot
-- earlier this morning thief withdrawing money ATM on Leggett Street
-- thief made phone call less than 1 minute when he left the bakery and take earliest flight out of Fiftyville tomorrow. 07/29/2023

SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour =10;
-- 5P2BI95
-- 94KL13X

SELECT * FROM people WHERE license_plate = '5P2BI95';
-- Vanessa (725) 555-4692 id 221103 passport_number 2963008352

SELECT * FROM people WHERE license_plate = '94KL13X';
-- Bruce  (367) 555-5533 id 686048 passport_number 5773159633

SELECT * FROM atm_transactions WHERE atm_location LIKE '%Leggett%' AND month = 7 AND day = 28 AND transaction_type = 'withdraw';

SELECT p.id, p.name, p.phone_number, p.passport_number, p.license_plate FROM atm_transactions at JOIN bank_accounts ba ON at.account_number = ba.account_number JOIN people p ON ba.person_id = p.id WHERE at.atm_location LIKE '%Leggett%' AND at.transaction_type = 'withdraw' AND at.day = 28 AND at.month = 7;
-- I find again Bruce in the list of people
-- But I need to check also phone calls and airports

SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2023 AND duration < 60;
--  I find Bruce phone number in 45 seconds receiver number is (375) 555-8161

SELECT * FROM flights WHERE year= 2023 AND month = 7 AND day = 29;

-- find the name of thief
SELECT people.name FROM flights JOIN airports ON flights.origin_airport_id=airports.id JOIN passengers ON flights.id = passengers.flight_id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.year= 2023 AND flights.month = 7 AND day = 29 AND people.license_plate ='94KL13X';
-- Name is Bruce

-- find the destination
SELECT flights.destination_airport_id FROM flights JOIN airports ON flights.origin_airport_id=airports.id JOIN passengers ON flights.id = passengers.flight_id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.year= 2023 AND flights.month = 7 AND day = 29 AND people.license_plate ='94KL13X';

-- id = 4

SELECT full_name, city FROM airports WHERE id = 4;

-- New York City

-- find the receiver

SELECT name FROM people WHERE phone_number = '(375) 555-8161';

--His name is Robin
