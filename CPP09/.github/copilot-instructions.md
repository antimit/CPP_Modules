# AI Coding Guidelines for CPP09

- **Scope**: Three standalone C++98 console programs in `ex00`, `ex01`, `ex02`; each has its own `Makefile` and binary.
- **Toolchain**: Compile with `c++ -Wall -Wextra -Werror -std=c++98`; avoid C++11+ features. Use per-exercise builds (`cd ex0X && make`, `make clean/fclean/re`).
- **Inputs/Outputs**: Programs rely on argv; no interactive prompts. Errors print concise messages (often just `Error`), then exit non-zero.

## ex00 – BitcoinExchange (`btc`)
- Data source fixed to `data.csv` in the same directory via `DATABASE_FILENAME` in [ex00/BitcoinExchange.cpp](ex00/BitcoinExchange.cpp).
- Expected input: file path argument containing lines like `YYYY-MM-DD | value`; header `date | value` is skipped. Whitespace is trimmed.
- Validation rules: date format and logical validity, numeric value must be 0–1000, positive only. Database CSV parsed with the same date/number checks; any bad line triggers "Critical error".
- Rate lookup: if an exact date is missing, uses the closest earlier date (falls back to earliest entry). Output: `date => amount = amount*rate`.
- Typical run: `cd ex00 && make && ./btc test_input.txt`.

## ex01 – Reverse Polish Notation (`RPN`)
- Single argument: space-separated tokens; integers may have leading +/-. Supported ops: `+ - * /` from [ex01/RPN.cpp](ex01/RPN.cpp).
- Evaluation uses a `std::stack<int>`; any malformed token, insufficient operands, or division by zero prints `Error` and exits 1. Success prints the final stack value and exits 0.
- Usage: `cd ex01 && make && ./RPN "3 4 + 2 *"`.

## ex02 – PmergeMe (Ford–Johnson sorter)
- Validates all args as non-negative ints within `INT_MAX`; any failure prints `Error` and exits 1 (see [ex02/main.cpp](ex02/main.cpp)).
- Displays sequences truncated to 5 elements with `[...]` if longer; times vector and list sorts separately in microseconds.
- Vector sort: [ex02/PmergeMe.cpp](ex02/PmergeMe.cpp) implements Ford–Johnson with Jacobsthal insertion order; keeps stable tie-breaking by original index.
- List sort: expected to mirror vector logic; note the current `mergeInsertList` signature in the `.cpp` does not match the `.hpp`, so adjust consistently before extending.
- Example: `cd ex02 && make && ./PmergeMe 3 5 9 1 2 8`.

## Conventions & Tips
- Keep error wording consistent with existing messages; avoid extra verbosity unless fixing a bug.
- Keep parsing helpers simple (manual `std::istringstream`, `isdigit`, trimming) to stay C++98-compatible.
- When adding features, consider each exercise independent; don't introduce shared cross-exercise headers or libs unless required.
- Maintain deterministic ordering when handling duplicates (see index tie-breaks in the sorter) and preserve current boundary behaviors (e.g., ex00 choosing closest earlier rate).
