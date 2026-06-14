class MundialLogic:
    def __init__(self):
        self.teams = self._initialize_teams()
        self.played_matches = set()

    def _initialize_teams(self):
        return {
            "Polska": {"points": 0, "goals_scored": 0, "goals_conceded": 0},
            "Niemcy": {"points": 0, "goals_scored": 0, "goals_conceded": 0},
            "Argentyna": {"points": 0, "goals_scored": 0, "goals_conceded": 0},
            "Ukraina": {"points": 0, "goals_scored": 0, "goals_conceded": 0}
        }

    def get_team_names(self):
        return list(self._initialize_teams().keys())

    def add_match(self, team1, team2, g1, g2):
        if team1 == team2:
            return False, "Drużyna nie może grać sama ze sobą!"

        if team1 not in self.teams or team2 not in self.teams:
            return False, "Błąd wyboru drużyn."

        match_pair = frozenset([team1, team2])
        if match_pair in self.played_matches:
            return False, "Te drużyny już rozegrały ze sobą mecz w tej fazie!"

        self.teams[team1]["goals_scored"] += g1
        self.teams[team1]["goals_conceded"] += g2
        self.teams[team2]["goals_scored"] += g2
        self.teams[team2]["goals_conceded"] += g1

        if g1 > g2:
            self.teams[team1]["points"] += 3
        elif g2 > g1:
            self.teams[team2]["points"] += 3
        else:
            self.teams[team1]["points"] += 1
            self.teams[team2]["points"] += 1

        self.played_matches.add(match_pair)

        return True, ""

    def reset_standings(self):
        self.teams = self._initialize_teams()
        self.played_matches.clear()

    def get_standings(self):
        standings = []
        for name, stats in self.teams.items():
            goal_diff = stats["goals_scored"] - stats["goals_conceded"]
            standings.append({
                "name": name,
                "points": stats["points"],
                "gd": goal_diff,
                "gs": stats["goals_scored"],
                "gc": stats["goals_conceded"]
            })

        standings.sort(key=lambda x: (x["points"], x["gd"], x["gs"]), reverse=True)

        return [
            f"{i + 1}. {team['name']:<10} | Pkt: {team['points']:<2} | Bilans: {team['gd']:<3} | Gole: {team['gs']}-{team['gc']}"
            for i, team in enumerate(standings)
        ]