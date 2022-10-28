-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First, we run .schema on all the tables, so we can see the structures of each table and make its correspondent link to other ones.
-- Now, let´s see what happened on the day and street given:

SELECT description
FROM crime_scene_reports
WHERE month = "7" AND day = 28
AND street = "Humphrey Street";

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- The next logic step is to look for the interviews so we figure out what they said, we look for the name and transcript of the three witnesses, as the three of them talks about the bakery, we select their transcripts

SELECT name,transcript FROM interviews WHERE month = "7" AND day = 28;

-- RUTH :  Thief left in a car, 10 minutes frame time, bakery.
--Check for the Bakery Security Logs. * To see all the info

SELECT * FROM bakery_security_logs where month = "7" AND day = 28;

-- Focusing on the info we want:

SELECT license_plate FROM bakery_security_logs where month = "7" AND day = 28
AND hour = 10 AND minute > 14 AND minute < 35
AND activity = "exit";

-- Result :  5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55 license plates left at the range time

-- Look for the people that matches the license_plates and extract all their data.

SELECT *
FROM people
WHERE license_plate IN ("5P2BI95", "94KL13X", "6P58WS2", "4328GD8", "G412CB7", "L93JTIZ", "322W7JE", "0NTHK55");

-- Suspects Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce

-- EUGENE :  Recognizes thief. Thief withdraw money before robbery. Atm on Leggett Street.

-- Look for the withdrawals that day on the mentioned street, take account_numbers

SELECT account_number
FROM atm_transactions
WHERE month = "7" AND day = 28
AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";

-- Accounts :  28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199

-- Look for the owners of the accounts found

SELECT name FROM people
JOIN bank_accounts
ON bank_accounts.person_id = people.id
WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);

-- Names that matches with suspects:
-- Iman  | (829) 555-5269
-- Luca  | (389) 555-5198
-- Diana | (770) 555-1861
-- Bruce | (367) 555-5533

-- Raymond : Thief called someone, call duration less than a minute. Tell him or her to purchase earliest flight the next day.

-- Look for calls with duration of less than a minute that day:

SELECT caller, receiver, duration FROM phone_calls
WHERE month = "7" AND day = 28
AND duration < 60;

-- Matching suspects with calls:
-- Diana | (770) 555-1861 | Receiver : (725) 555-3243
-- Bruce | (367) 555-5533 | Receiver : (375) 555-8161

-- Passports from Diana and Bruce:

SELECT name, passport_number
FROM people
WHERE phone_number IN ("(770) 555-1861", "(367) 555-5533");

-- Diana | 3592750733
-- Bruce | 5773159633

-- Look for flights done by those passports

SELECT flight_id FROM passengers
WHERE passport_number IN (3592750733, 5773159633);

-- Flight IDs : 18, 24, 36, 54

SELECT * FROM flights
WHERE id IN (18,24,36,54)
AND day = 29;

-- Earliest flight: id 36, Origin id 8, destination id 4, 8:20

-- Find the passenger from suspects that was on the flight id36

SELECT passport_number FROM passengers
JOIN flights
ON flights.id = passengers.flight_id
WHERE flights.id = 36
AND passport_number IN (3592750733, 5773159633);

-- suspect number one : BRUCE

-- Check where he went: New York City

SELECT city FROM airports WHERE id = 4;


-- Check who helped him: Robin

SELECT name FROM people
WHERE phone_number = "(375) 555-8161";

