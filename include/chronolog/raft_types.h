#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace chronolog {
namespace raft {

using NodeId = std::string;
using Term = uint64_t;
using LogIndex = uint64_t;
using Command = std::string;

enum class NodeState {
    FOLLOWER,
    CANDIDATE, 
    LEADER
};

inline std::string to_string(NodeState state) {
    switch (state) {
        case NodeState::FOLLOWER: return "FOLLOWER";
        case NodeState::CANDIDATE: return "CANDIDATE";
        case NodeState::LEADER: return "LEADER";
        default: return "UNKNOWN";
    }
}

struct LogEntry {
    Term term;
    LogIndex index;
    Command command;
    
    LogEntry() : term(0), index(0) {}
    LogEntry(Term t, LogIndex i, const Command& cmd) 
        : term(t), index(i), command(cmd) {}
};

struct RequestVoteRequest {
    Term term;
    NodeId candidate_id;
    LogIndex last_log_index;
    Term last_log_term;
    
    RequestVoteRequest() : term(0), last_log_index(0), last_log_term(0) {}
};

struct RequestVoteResponse {
    Term term;
    bool vote_granted;
    
    RequestVoteResponse() : term(0), vote_granted(false) {}
    RequestVoteResponse(Term t, bool granted) : term(t), vote_granted(granted) {}
};

struct AppendEntriesRequest {
    Term term;
    NodeId leader_id;
    LogIndex prev_log_index;
    Term prev_log_term;
    std::vector<LogEntry> entries;
    LogIndex leader_commit;
    
    AppendEntriesRequest() : term(0), prev_log_index(0), prev_log_term(0), leader_commit(0) {}
};

struct AppendEntriesResponse {
    Term term;
    bool success;
    LogIndex match_index;
    
    AppendEntriesResponse() : term(0), success(false), match_index(0) {}
    AppendEntriesResponse(Term t, bool s, LogIndex match = 0) 
        : term(t), success(s), match_index(match) {}
};

struct ClientRequest {
    Command command;
    
    ClientRequest() = default;
    ClientRequest(const Command& cmd) : command(cmd) {}
};

struct ClientResponse {
    bool success;
    std::string error;
    NodeId leader_id;
    
    ClientResponse() : success(false) {}
    ClientResponse(bool s, const std::string& err = "", const NodeId& leader = "") 
        : success(s), error(err), leader_id(leader) {}
};

} // namespace raft
} // namespace chronolog
